#include "overlay.h"
#include "log/log.h"
#include "log/stub.h"

#include "log/abort.h"

#include <cstring>

using namespace openvr;

OverlayImpl::OverlayImpl(ClientCoreImpl& clientCore): clientCore(clientCore)
{
    // empty
}

OverlayImpl::~OverlayImpl()
{
    // TODO
}

OverlayError OverlayImpl::findOverlay(const char* key, uint64_t* handle)
{
    TRACE_F("%s", key);
    Overlay* overlay = lookupOverlay(key);
    if (overlay != nullptr)
    {
        *handle = overlay->handle;
        return OverlayError::OVERLAY_ERROR_NONE;
    }
    *handle = 0;
    return OverlayError::OVERLAY_ERROR_UNKNOWN_OVERLAY;
}

OverlayError OverlayImpl::createOverlay(const char* key, const char* name, uint64_t* handle)
{
    TRACE_F("%s %s", key, name);

    Overlay* overlay = lookupOverlay(key);
    if (overlay != nullptr)
    {
        *handle = overlay->handle;
        return OverlayError::OVERLAY_ERROR_KEY_IN_USE;
    }
    overlay = storeNewOverlay(key);
    if (overlay == nullptr)
    {
        ABORT();
    }
    *handle = overlay->handle;

    overlay->window = new vapor::windows::Window();
    overlay->window->title = name;
    this->clientCore.backend->windowManager->addWindow(overlay->window);

    return OverlayError::OVERLAY_ERROR_NONE;
}

OverlayError OverlayImpl::createDashboardOverlay(const char* key, const char* name, uint64_t* mainHandle, uint64_t* thumbnailHandle)
{
    // TODO
    STUB_F("%s %s", key, name);
    *mainHandle = *thumbnailHandle = 0;
    // TODO: testing
    createOverlay(key, name, mainHandle);
    // TODO: set dashboard flag on overlay
    return OverlayError::OVERLAY_ERROR_REQUEST_FAILED;
}

OverlayError OverlayImpl::createSubviewOverlay(uint64_t parentHandle, const char* key, const char* name, uint64_t* handle)
{
    // TODO
    STUB_F("%lu %s %s", parentHandle, key, name);
    *handle = 0;
    return OverlayError::OVERLAY_ERROR_REQUEST_FAILED;
}

OverlayError OverlayImpl::destroyOverlay(uint64_t handle)
{
    TRACE_F("%lu", handle);

    Overlay* overlay = getOverlay(handle);
    if (overlay == nullptr)
    {
        return OverlayError::OVERLAY_ERROR_INVALID_HANDLE;
    }

    // TODO: handle windows that have a relation e.g. subview/child position/cursor/dashboard icon
    this->clientCore.backend->windowManager->removeWindow(overlay->window);
    delete overlay->window;

    removeOverlay(handle);

    return OverlayError::OVERLAY_ERROR_NONE;
}

uint32_t OverlayImpl::getOverlayKey(uint64_t handle, char* value, uint32_t bufferSize, OverlayError* error)
{
    Overlay* overlay = getOverlay(handle);
    if (overlay == nullptr)
    {
        if (error != nullptr)
        {
            *error = OverlayError::OVERLAY_ERROR_INVALID_HANDLE;
            return 0;
        }
    }
    if (error != nullptr)
    {
        *error = OverlayError::OVERLAY_ERROR_NONE;
    }

    uint32_t requiredBufferSize = overlay->key.length() + 1;
    if (bufferSize >= requiredBufferSize)
    {
        std::memcpy(value, overlay->key.c_str(), requiredBufferSize);
    }
    return requiredBufferSize;
}

uint32_t OverlayImpl::getOverlayName(uint64_t handle, char* value, uint32_t bufferSize, OverlayError* error)
{
    Overlay* overlay = getOverlay(handle);
    if (overlay == nullptr)
    {
        if (error != nullptr)
        {
            *error = OverlayError::OVERLAY_ERROR_INVALID_HANDLE;
            return 0;
        }
    }
    if (error != nullptr)
    {
        *error = OverlayError::OVERLAY_ERROR_NONE;
    }

    uint32_t requiredBufferSize = overlay->window->title.length() + 1;
    if (bufferSize >= requiredBufferSize)
    {
        std::memcpy(value, overlay->window->title.c_str(), requiredBufferSize);
    }
    return requiredBufferSize;
}

OverlayError OverlayImpl::setOverlayName(uint64_t handle, const char* name)
{
    TRACE_F("%lu %s", handle, name);
    Overlay* overlay = getOverlay(handle);
    if (overlay == nullptr)
    {
        return OverlayError::OVERLAY_ERROR_INVALID_HANDLE;
    }
    overlay->window->lock();
    overlay->window->title = name;
    overlay->window->unlock();
    return OverlayError::OVERLAY_ERROR_NONE;
}

OverlayError OverlayImpl::setOverlayFlag(uint64_t handle, uint32_t flags, bool enabled)
{
    // TODO: perform bitwise OR of new flags (or inverse of new flags, if enabled is false) with current flags
    STUB_F("%lu %u %d", handle, flags, enabled);
    return OverlayError::OVERLAY_ERROR_NONE;
}

OverlayError OverlayImpl::getOverlayFlag(uint64_t handle, uint32_t flags, bool* enabled)
{
    // TODO: perform bitwise AND of provided flags with current flags and return true if non-zero
    STUB_F("%lu %u", handle, flags);
    return OverlayError::OVERLAY_ERROR_NONE;
}

OverlayError OverlayImpl::getOverlayFlags(uint64_t handle, uint32_t* flags)
{
    // TODO
    STUB_F("%lu", handle);
    return OverlayError::OVERLAY_ERROR_NONE;
}

OverlayError OverlayImpl::setOverlayColor(uint64_t handle, float r, float g, float b)
{
    // TODO
    STUB_F("%lu %f %f %f", handle, r, g, b);
    return OverlayError::OVERLAY_ERROR_NONE;
}

OverlayError OverlayImpl::getOverlayColor(uint64_t handle, float* r, float* g, float* b)
{
    // TODO
    STUB_F("%lu", handle);
    return OverlayError::OVERLAY_ERROR_NONE;
}

OverlayError OverlayImpl::setOverlayAlpha(uint64_t handle, float alpha)
{
    TRACE_F("%lu %f", handle, alpha);
    Overlay* overlay = getOverlay(handle);
    if (overlay == nullptr)
    {
        return OverlayError::OVERLAY_ERROR_INVALID_HANDLE;
    }
    overlay->window->lock();
    overlay->window->alpha = alpha;
    overlay->window->unlock();
    return OverlayError::OVERLAY_ERROR_NONE;
}

OverlayError OverlayImpl::getOverlayAlpha(uint64_t handle, float* alpha)
{
    Overlay* overlay = getOverlay(handle);
    if (overlay == nullptr)
    {
        return OverlayError::OVERLAY_ERROR_INVALID_HANDLE;
    }
    overlay->window->lock();
    *alpha = overlay->window->alpha;
    overlay->window->unlock();
    return OverlayError::OVERLAY_ERROR_NONE;
}

OverlayError OverlayImpl::setOverlayGamma(uint64_t handle, float gamma)
{
    // TODO
    STUB_F("%lu %f", handle, gamma);
    return OverlayError::OVERLAY_ERROR_NONE;
}

OverlayError OverlayImpl::getOverlayGamma(uint64_t handle, float* gamma)
{
    // TODO
    STUB_F("%lu", handle);
    return OverlayError::OVERLAY_ERROR_NONE;
}

OverlayError OverlayImpl::setOverlayTexelAspectRatio(uint64_t handle, float aspect)
{
    Overlay* overlay = getOverlay(handle);
    if (overlay == nullptr)
    {
        return OverlayError::OVERLAY_ERROR_INVALID_HANDLE;
    }
    overlay->window->lock();
    overlay->window->texelAspectRatio = aspect;
    overlay->window->unlock();
    return OverlayError::OVERLAY_ERROR_NONE;
}

OverlayError OverlayImpl::getOverlayTexelAspectRatio(uint64_t handle, float* aspect)
{
    Overlay* overlay = getOverlay(handle);
    if (overlay == nullptr)
    {
        return OverlayError::OVERLAY_ERROR_INVALID_HANDLE;
    }
    *aspect = overlay->window->texelAspectRatio;
    return OverlayError::OVERLAY_ERROR_NONE;
}

OverlayError OverlayImpl::setOverlaySortOrder(uint64_t handle, uint32_t sortOrder)
{
    TRACE_F("%lu %u", handle, sortOrder);
    Overlay* overlay = getOverlay(handle);
    if (overlay == nullptr)
    {
        return OverlayError::OVERLAY_ERROR_INVALID_HANDLE;
    }
    overlay->window->lock();
    overlay->window->sortOrder = sortOrder;
    overlay->window->unlock();
    return OverlayError::OVERLAY_ERROR_NONE;
}

OverlayError OverlayImpl::getOverlaySortOrder(uint64_t handle, uint32_t* sortOrder)
{
    Overlay* overlay = getOverlay(handle);
    if (overlay == nullptr)
    {
        return OverlayError::OVERLAY_ERROR_INVALID_HANDLE;
    }
    overlay->window->lock();
    *sortOrder = overlay->window->sortOrder;
    overlay->window->unlock();
    return OverlayError::OVERLAY_ERROR_NONE;
}

OverlayError OverlayImpl::setOverlayWidthInMeters(uint64_t handle, float width)
{
    Overlay* overlay = getOverlay(handle);
    if (overlay == nullptr)
    {
        return OverlayError::OVERLAY_ERROR_INVALID_HANDLE;
    }
    overlay->window->lock();
    overlay->window->widthInMeters = width;
    overlay->window->unlock();
    return OverlayError::OVERLAY_ERROR_NONE;
}

OverlayError OverlayImpl::getOverlayWidthInMeters(uint64_t handle, float* width)
{
    Overlay* overlay = getOverlay(handle);
    if (overlay == nullptr)
    {
        return OverlayError::OVERLAY_ERROR_INVALID_HANDLE;
    }
    *width = overlay->window->widthInMeters;
    return OverlayError::OVERLAY_ERROR_NONE;
}

OverlayError OverlayImpl::setOverlayAutoCurveDistanceRangeInMeters(uint64_t handle, float minDistance, float maxDistance)
{
    // TODO
    STUB_F("%lu %f %f", handle, minDistance, maxDistance);
    return OverlayError::OVERLAY_ERROR_NONE;
}

OverlayError OverlayImpl::getOverlayAutoCurveDistanceRangeInMeters(uint64_t handle, float* minDistance, float* maxDistance)
{
    // TODO
    STUB_F("%lu", handle);
    return OverlayError::OVERLAY_ERROR_NONE;
}

OverlayError OverlayImpl::setOverlayCurvature(uint64_t handle, float curvature)
{
    // TODO
    STUB_F("%lu %f", handle, curvature);
    return OverlayError::OVERLAY_ERROR_NONE;
}

OverlayError OverlayImpl::getOverlayCurvature(uint64_t handle, float* curvature)
{
    // TODO
    STUB_F("%lu", handle);
    return OverlayError::OVERLAY_ERROR_NONE;
}

OverlayError OverlayImpl::setOverlayPreCurvePitch(uint64_t handle, float radians)
{
    // TODO
    STUB_F("%lu %f", handle, radians);
    return OverlayError::OVERLAY_ERROR_NONE;
}

OverlayError OverlayImpl::getOverlayPreCurvePitch(uint64_t handle, float* radians)
{
    // TODO
    STUB_F("%lu", handle);
    return OverlayError::OVERLAY_ERROR_NONE;
}

OverlayError OverlayImpl::getTransformForOverlayCoordinates(uint64_t handle, TrackingUniverseOrigin origin, Vector2 coordinatesInOverlay, Matrix34* matrix)
{
    // TODO
    STUB_F("%lu", handle);
    return OverlayError::OVERLAY_ERROR_NONE;
}

OverlayError OverlayImpl::getOverlayTransformType(uint64_t handle, OverlayTransformType* transformType)
{
    Overlay* overlay = getOverlay(handle);
    if (overlay == nullptr)
    {
        return OverlayError::OVERLAY_ERROR_INVALID_HANDLE;
    }
    const vapor::windows::Transform* transform = overlay->window->transform;
    if (transform == nullptr)
    {
        *transformType = OverlayTransformType::OVERLAY_TRANSFORM_TYPE_INVALID;
    }
    else
    {
        *transformType = transform->getTransformType();
    }
    return OverlayError::OVERLAY_ERROR_NONE;
}

template<typename T> inline T* getOverlayTransformAndCheckType(vapor::windows::Transform* transform, openvr::OverlayTransformType transformType)
{
    if (transform == nullptr)
    {
        return nullptr;
    }
    if (transform->getTransformType() != transformType)
    {
        return nullptr;
    }
    return (T*) transform;
}

OverlayError OverlayImpl::setOverlayTransformAbsolute(uint64_t handle, TrackingUniverseOrigin origin, const Matrix34* matrix)
{
    TRACE_F("%lu", handle);
    Overlay* overlay = getOverlay(handle);
    if (overlay == nullptr)
    {
        return OverlayError::OVERLAY_ERROR_INVALID_HANDLE;
    }
    overlay->window->lock();
    delete overlay->window->transform;
    overlay->window->transform = new vapor::windows::AbsoluteTransform(origin, *matrix);
    overlay->window->unlock();
    return OverlayError::OVERLAY_ERROR_NONE;
}

OverlayError OverlayImpl::getOverlayTransformAbsolute(uint64_t handle, TrackingUniverseOrigin* origin, Matrix34* matrix)
{
    TRACE_F("%lu", handle);
    Overlay* overlay = getOverlay(handle);
    if (overlay == nullptr)
    {
        return OverlayError::OVERLAY_ERROR_INVALID_HANDLE;
    }
    const vapor::windows::AbsoluteTransform* transform = getOverlayTransformAndCheckType<vapor::windows::AbsoluteTransform>(overlay->window->transform, OverlayTransformType::OVERLAY_TRANSFORM_TYPE_ABSOLUTE);
    if (transform == nullptr)
    {
        return OverlayError::OVERLAY_ERROR_WRONG_TRANSFORM_TYPE;
    }
    *origin = transform->trackingUniverse;
    *matrix = transform->offset;
    return OverlayError::OVERLAY_ERROR_NONE;
}

OverlayError OverlayImpl::setOverlayTransformTrackedDeviceRelative(uint64_t handle, uint32_t trackedDeviceIndex, const Matrix34* matrix)
{
    TRACE_F("%lu %u", handle, trackedDeviceIndex);
    Overlay* overlay = getOverlay(handle);
    if (overlay == nullptr)
    {
        return OverlayError::OVERLAY_ERROR_INVALID_HANDLE;
    }
    if (trackedDeviceIndex < 0 || trackedDeviceIndex > 2)
    {
        return OverlayError::OVERLAY_ERROR_INVALID_TRACKED_DEVICE;
    }
    overlay->window->lock();
    delete overlay->window->transform;
    overlay->window->transform = new vapor::windows::TrackedDeviceRelativeTransform(trackedDeviceIndex, *matrix);
    overlay->window->unlock();
    return OverlayError::OVERLAY_ERROR_NONE;
}

OverlayError OverlayImpl::getOverlayTransformTrackedDeviceRelative(uint64_t handle, uint32_t* trackedDeviceIndex, Matrix34* matrix)
{
    TRACE_F("%lu", handle);
    Overlay* overlay = getOverlay(handle);
    if (overlay == nullptr)
    {
        return OverlayError::OVERLAY_ERROR_INVALID_HANDLE;
    }
    const vapor::windows::TrackedDeviceRelativeTransform* transform = getOverlayTransformAndCheckType<vapor::windows::TrackedDeviceRelativeTransform>(overlay->window->transform, OverlayTransformType::OVERLAY_TRANSFORM_TYPE_TRACKED_DEVICE_RELATIVE);
    if (transform == nullptr)
    {
        return OverlayError::OVERLAY_ERROR_WRONG_TRANSFORM_TYPE;
    }
    *trackedDeviceIndex = transform->deviceIndex;
    *matrix = transform->offset;
    return OverlayError::OVERLAY_ERROR_NONE;
}

OverlayError OverlayImpl::setOverlayTransformTrackedDeviceComponent(uint64_t handle, uint32_t trackedDeviceIndex, const char* componentName)
{
    // TODO
    STUB_F("%lu %u %s", handle, trackedDeviceIndex, componentName);
    return OverlayError::OVERLAY_ERROR_NONE;
}

OverlayError OverlayImpl::getOverlayTransformTrackedDeviceComponent(uint64_t handle, uint32_t* trackedDeviceIndex, char* componentName, uint32_t bufferSize)
{
    // TODO
    STUB_F("%lu", handle);
    return OverlayError::OVERLAY_ERROR_NONE;
}

OverlayError OverlayImpl::setOverlayTransformOverlayRelative(uint64_t handle, uint64_t parentHandle, const Matrix34* matrix)
{
    // TODO
    STUB_F("%lu", handle);
    return OverlayError::OVERLAY_ERROR_NONE;
}

OverlayError OverlayImpl::getOverlayTransformOverlayRelative(uint64_t handle, uint64_t* parentHandle, Matrix34* matrix)
{
    // TODO
    STUB_F("%lu", handle);
    return OverlayError::OVERLAY_ERROR_NONE;
}

OverlayError OverlayImpl::setOverlayTransformOverlayCursor(uint64_t handle, const Vector2* hotspot)
{
    // TODO
    STUB_F("%lu", handle);
    return OverlayError::OVERLAY_ERROR_NONE;
}

OverlayError OverlayImpl::getOverlayTransformOverlayCursor(uint64_t handle, Vector2* hotspot)
{
    // TODO
    STUB_F("%lu", handle);
    return OverlayError::OVERLAY_ERROR_NONE;
}

OverlayError OverlayImpl::setOverlayTransformProjection(uint64_t handle, TrackingUniverseOrigin origin, const Matrix34* matrix, const OverlayProjection* projection, Eye eye)
{
    // TODO
    STUB_F("%lu", handle);
    return OverlayError::OVERLAY_ERROR_NONE;
}

OverlayError OverlayImpl::setSubviewOverlayPosition(uint64_t handle, float x, float y)
{
    // TODO
    STUB_F("%lu", handle);
    return OverlayError::OVERLAY_ERROR_NONE;
}

OverlayError OverlayImpl::showOverlay(uint64_t handle)
{
    TRACE_F("%lu", handle);
    Overlay* overlay = getOverlay(handle);
    if (overlay == nullptr)
    {
        return OverlayError::OVERLAY_ERROR_INVALID_HANDLE;
    }
    overlay->window->lock();
    overlay->window->visible = true;
    overlay->window->unlock();
    return OverlayError::OVERLAY_ERROR_NONE;
}

OverlayError OverlayImpl::hideOverlay(uint64_t handle)
{
    TRACE_F("%lu", handle);
    Overlay* overlay = getOverlay(handle);
    if (overlay == nullptr)
    {
        return OverlayError::OVERLAY_ERROR_INVALID_HANDLE;
    }
    overlay->window->lock();
    overlay->window->visible = false;
    overlay->window->unlock();
    return OverlayError::OVERLAY_ERROR_NONE;
}

bool OverlayImpl::isOverlayVisible(uint64_t handle)
{
    TRACE_F("%lu", handle);
    Overlay* overlay = getOverlay(handle);
    if (overlay == nullptr)
    {
        return false;
    }
    bool visible;
    overlay->window->lock();
    if (!overlay->window->dashboard)
    {
        visible = overlay->window->visible;
    }
    else
    {
        // TODO: return true for dashboard overlays when dashboard is open
        visible = false;
    }
    overlay->window->unlock();
    return visible;
}

OverlayError OverlayImpl::legacyIsDashboardOverlay(uint64_t handle, bool* dashboard)
{
    TRACE_F("%lu", handle);
    Overlay* overlay = getOverlay(handle);
    if (overlay == nullptr)
    {
        return OverlayError::OVERLAY_ERROR_INVALID_HANDLE;
    }
    overlay->window->lock();
    *dashboard = overlay->window->dashboard;
    overlay->window->unlock();
    return OverlayError::OVERLAY_ERROR_NONE;
}

OverlayError OverlayImpl::legacySetAsDashboardOverlay(uint64_t handle, bool dashboard)
{
    TRACE_F("%lu %d", handle, dashboard);
    Overlay* overlay = getOverlay(handle);
    if (overlay == nullptr)
    {
        return OverlayError::OVERLAY_ERROR_INVALID_HANDLE;
    }
    overlay->window->lock();
    overlay->window->dashboard = dashboard;
    overlay->window->unlock();
    return OverlayError::OVERLAY_ERROR_NONE;
}

bool OverlayImpl::isDashboardVisible()
{
    // TODO
    STUB();
    return false;
}

bool OverlayImpl::isActiveDashboardOverlay(uint64_t handle)
{
    // TODO
    STUB_F("%lu", handle);
    return false;
}

OverlayError OverlayImpl::showDashboard(const char* key)
{
    // TODO
    STUB_F("%s", key);
    return OverlayError::OVERLAY_ERROR_NONE;
}

OverlayError OverlayImpl::getOverlayImageData(uint64_t handle, void* buffer, uint32_t bufferSize, uint32_t* width, uint32_t* height)
{
    // TODO
    STUB_F("%lu", handle);
    return OverlayError::OVERLAY_ERROR_NONE;
}

OverlayError OverlayImpl::setOverlayTextureColorSpace(uint64_t handle, ColorSpace colorSpace)
{
    // TODO
    STUB_F("%lu %d", handle, colorSpace);
    return OverlayError::OVERLAY_ERROR_NONE;
}

OverlayError OverlayImpl::getOverlayTextureColorSpace(uint64_t handle, ColorSpace* colorSpace)
{
    // TODO
    STUB_F("%lu", handle);
    return OverlayError::OVERLAY_ERROR_NONE;
}

OverlayError OverlayImpl::setOverlayTextureBounds(uint64_t handle, const TextureBounds* bounds)
{
    TRACE_F("%lu %f %f %f %f", handle, bounds->uMin, bounds->vMin, bounds->uMax, bounds->vMax);
    Overlay* overlay = getOverlay(handle);
    if (overlay == nullptr)
    {
        return OverlayError::OVERLAY_ERROR_INVALID_HANDLE;
    }
    overlay->window->lock();
    overlay->window->textureBounds[0] = bounds->uMin;
    overlay->window->textureBounds[1] = bounds->vMin;
    overlay->window->textureBounds[2] = bounds->uMax;
    overlay->window->textureBounds[3] = bounds->vMax;
    overlay->window->unlock();
    return OverlayError::OVERLAY_ERROR_NONE;
}

OverlayError OverlayImpl::getOverlayTextureBounds(uint64_t handle, TextureBounds* bounds)
{
    TRACE_F("%lu %d", handle, bounds);
    Overlay* overlay = getOverlay(handle);
    if (overlay == nullptr)
    {
        return OverlayError::OVERLAY_ERROR_INVALID_HANDLE;
    }
    overlay->window->lock();
    bounds->uMin = overlay->window->textureBounds[0];
    bounds->vMin = overlay->window->textureBounds[1];
    bounds->uMax = overlay->window->textureBounds[2];
    bounds->vMax = overlay->window->textureBounds[3];
    overlay->window->unlock();
    return OverlayError::OVERLAY_ERROR_NONE;
}

OverlayError OverlayImpl::setOverlayTexture(uint64_t handle, const Texture* texture)
{
    TRACE_F("%lu %d %d", handle, texture->type, texture->colorSpace);

    Overlay* overlay = getOverlay(handle);
    if (overlay == nullptr)
    {
        return OverlayError::OVERLAY_ERROR_INVALID_HANDLE;
    }

    overlay->window->lock();

    vapor::image_capture::ImageCaptureBufferManager<int>& imageCaptureBuffer = overlay->window->getImageCaptureBuffer();

    CompositorError captureError;
    if (texture->type == TextureType::TEXTURE_TYPE_OPENGL)
    {
        captureError = imageCaptureBuffer.captureOpenGL((GLuint) (uint64_t) texture->handle);
    }
    else if (texture->type == TextureType::TEXTURE_TYPE_VULKAN)
    {
        const VulkanTextureData* textureData = (VulkanTextureData*) texture->handle;
        captureError = imageCaptureBuffer.captureVulkan(textureData, 0);
    }
    else
    {
        STUB_F("Unsupported texture type %d", texture->type);
        overlay->window->unlock();
        return OverlayError::OVERLAY_ERROR_REQUEST_FAILED;
    }

    if (captureError != CompositorError::COMPOSITOR_ERROR_NONE)
    {
        // TODO: properly translate relevant error values
        overlay->window->unlock();
        return OverlayError::OVERLAY_ERROR_REQUEST_FAILED;
    }

    imageCaptureBuffer.swapBuffers();
    overlay->window->activateGpuImage();

    overlay->window->unlock();

    return OverlayError::OVERLAY_ERROR_NONE;
}

OverlayError OverlayImpl::clearOverlayTexture(uint64_t handle)
{
    TRACE_F("%lu", handle);
    Overlay* overlay = getOverlay(handle);
    if (overlay == nullptr)
    {
        return OverlayError::OVERLAY_ERROR_INVALID_HANDLE;
    }
    overlay->window->clearImage();
    return OverlayError::OVERLAY_ERROR_NONE;
}

OverlayError OverlayImpl::setOverlayRaw(uint64_t handle, void* buffer, uint32_t width, uint32_t height, uint32_t depth)
{
    TRACE_F("%lu %u %u %u", handle, width, height, depth);
    Overlay* overlay = getOverlay(handle);
    if (overlay == nullptr)
    {
        return OverlayError::OVERLAY_ERROR_INVALID_HANDLE;
    }
    overlay->window->submitCpuImage(buffer, width, height, depth);
    return OverlayError::OVERLAY_ERROR_NONE;
}

OverlayError OverlayImpl::setOverlayFromFile(uint64_t handle, const char* filePath)
{
    // TODO
    STUB_F("%lu %s", handle, filePath);
    return OverlayError::OVERLAY_ERROR_NONE;
}

OverlayError OverlayImpl::getOverlayNativeTexture(uint64_t handle, void** nativeTextureHandle, void* nativeTextureRef, uint32_t* width, uint32_t* height, uint32_t* format, TextureType* type, ColorSpace* colorSpace, TextureBounds* bounds)
{
    // TODO
    STUB_F("%lu", handle);
    return OverlayError::OVERLAY_ERROR_NONE;
}

OverlayError OverlayImpl::releaseNativeOverlayTexture(uint64_t handle, void* nativeTextureHandle)
{
    // TODO
    STUB_F("%lu", handle);
    return OverlayError::OVERLAY_ERROR_NONE;
}

OverlayError OverlayImpl::getOverlayTextureSize(uint64_t handle, uint32_t* width, uint32_t* height)
{
    // TODO
    STUB_F("%lu", handle);
    return OverlayError::OVERLAY_ERROR_NONE;
}

OverlayError OverlayImpl::waitFrameSync(uint32_t timeout)
{
    // TODO
    STUB_F("%u", timeout);
    return OverlayError::OVERLAY_ERROR_NONE;
}

bool OverlayImpl::pollNextOverlayEvent(uint64_t handle, Event_0_9_15* event, uint32_t bufferSize)
{
    // TODO
    STUB_F("%lu", handle);
    return false;
}

OverlayError OverlayImpl::setOverlayInputMethod(uint64_t handle, OverlayInputMethod inputMethod)
{
    // TODO
    STUB_F("%lu %d", handle, inputMethod);
    return OverlayError::OVERLAY_ERROR_NONE;
}

OverlayError OverlayImpl::getOverlayInputMethod(uint64_t handle, OverlayInputMethod* inputMethod)
{
    // TODO
    STUB_F("%lu", handle);
    return OverlayError::OVERLAY_ERROR_NONE;
}

OverlayError OverlayImpl::setOverlayMouseScale(uint64_t handle, const Vector2* mouseScale)
{
    // TODO
    STUB_F("%lu", handle);
    return OverlayError::OVERLAY_ERROR_NONE;
}

OverlayError OverlayImpl::getOverlayMouseScale(uint64_t handle, Vector2* mouseScale)
{
    // TODO
    STUB_F("%lu", handle);
    return OverlayError::OVERLAY_ERROR_NONE;
}

OverlayError OverlayImpl::setOverlayCursor(uint64_t handle, uint64_t cursorHandle)
{
    // TODO
    STUB_F("%lu %lu", handle, cursorHandle);
    return OverlayError::OVERLAY_ERROR_NONE;
}

OverlayError OverlayImpl::setOverlayCursorPositionOverride(uint64_t handle, const Vector2* position)
{
    // TODO
    STUB_F("%lu", handle);
    return OverlayError::OVERLAY_ERROR_NONE;
}

OverlayError OverlayImpl::clearOverlayCursorPositionOverride(uint64_t handle)
{
    // TODO
    STUB_F("%lu", handle);
    return OverlayError::OVERLAY_ERROR_NONE;
}

OverlayError OverlayImpl::setOverlayIntersectionMask(uint64_t handle, OverlayIntersectionMaskPrimitive* primitives, uint32_t primitivesCount, uint32_t primitiveSize)
{
    // TODO
    STUB_F("%lu", handle);
    return OverlayError::OVERLAY_ERROR_NONE;
}

bool OverlayImpl::computeOverlayIntersection(uint64_t handle, const OverlayIntersectionParams* params, OverlayIntersectionResults* results)
{
    // TODO
    STUB_F("%lu", handle);
    return false;
}

bool OverlayImpl::handleControllerOverlayInteractionAsMouse(uint64_t handle, uint32_t controllerDeviceIndex)
{
    // TODO
    STUB_F("%lu %u", handle, controllerDeviceIndex);
    return false;
}

bool OverlayImpl::isHoverTargetOverlay(uint64_t handle)
{
    // TODO
    STUB_F("%lu", handle);
    return false;
}

OverlayError OverlayImpl::triggerLaserMouseHapticVibration(uint64_t handle, float durationSeconds, float frequency, float amplitude)
{
    // TODO
    STUB_F("%lu", handle);
    return OverlayError::OVERLAY_ERROR_NONE;
}

uint32_t OverlayImpl::getPrimaryDashboardInputTrackedDevice()
{
    // TODO
    STUB();
    return 0;
}

uint64_t OverlayImpl::getGamepadFocusOverlay()
{
    // TODO
    STUB();
    return 0;
}

OverlayError OverlayImpl::setGamepadFocusOverlay(uint64_t handle)
{
    // TODO
    STUB_F("%lu", handle);
    return OverlayError::OVERLAY_ERROR_NONE;
}

OverlayError OverlayImpl::setOverlayNeighbor(OverlayNeighborDirection direction, uint64_t from, uint64_t to)
{
    // TODO
    STUB_F("%d %lu %lu", from, to);
    return OverlayError::OVERLAY_ERROR_NONE;
}

OverlayError OverlayImpl::moveGamepadFocusToNeighbor(OverlayNeighborDirection direction, uint64_t from)
{
    // TODO
    STUB_F("%d %lu", direction, from);
    return OverlayError::OVERLAY_ERROR_NONE;
}

OverlayError OverlayImpl::setOverlayDualAnalogTransform(uint64_t handle, DualAnalogWhich which, const Vector2* center, float radius)
{
    // TODO
    STUB_F("%lu %d", handle, which);
    return OverlayError::OVERLAY_ERROR_NONE;
}

OverlayError OverlayImpl::getOverlayDualAnalogTransform(uint64_t handle, DualAnalogWhich which, Vector2* center, float* radius)
{
    // TODO
    STUB_F("%lu %d", handle, which);
    return OverlayError::OVERLAY_ERROR_NONE;
}

OverlayError OverlayImpl::showKeyboard(GamepadTextInputMode textInputMode, GamepadTextInputLineMode textInputLineMode, uint32_t flags, const char* description, uint32_t maxChars, const char* existingText, uint64_t userValue)
{
    // TODO
    STUB_F("%d %d %u %s %u %s %lu", textInputMode, textInputLineMode, flags, description, maxChars, existingText, userValue);
    return OverlayError::OVERLAY_ERROR_NONE;
}

OverlayError OverlayImpl::showKeyboardForOverlay(uint64_t handle, GamepadTextInputMode textInputMode, GamepadTextInputLineMode textInputLineMode, uint32_t flags, const char* description, uint32_t maxChars, const char* existingText, uint64_t userValue)
{
    // TODO
    STUB_F("%lu %d %d %u %s %u %s %lu", handle, textInputMode, textInputLineMode, flags, description, maxChars, existingText, userValue);
    return OverlayError::OVERLAY_ERROR_NONE;
}

uint32_t OverlayImpl::getKeyboardText(char* text, uint32_t bufferSize)
{
    // TODO
    STUB();
    return 0;
}

void OverlayImpl::hideKeyboard()
{
    // TODO
    STUB();
}

void OverlayImpl::setKeyboardTransformAbsolute(TrackingUniverseOrigin origin, const Matrix34* matrix)
{
    // TODO
    STUB();
}

void OverlayImpl::setKeyboardPositionForOverlay(uint64_t handle, Rect avoidRect)
{
    // TODO
    STUB_F("%lu", handle);
}

MessageOverlayResponse OverlayImpl::showMessageOverlay(const char* text, const char* caption, const char* button0Text, const char* button1Text, const char* button2Text, const char* button3Text)
{
    // TODO
    STUB_F("%s %s %s %s %s %s", text, caption, button0Text, button1Text, button2Text, button3Text);
    return MessageOverlayResponse::MESSAGE_OVERLAY_RESPONSE_COULDNT_FIND_SYSTEM_OVERLAY;
}

void OverlayImpl::closeMessageOverlay()
{
    // TODO
    STUB();
}

const char* OverlayImpl::getOverlayErrorNameFromEnum(OverlayError error)
{
    // TODO
    STUB_F("%d", error);
    return "";
}

//

static inline std::string stringToLowercase(const std::string& in)
{
    std::string out = in;
    std::transform(out.begin(), out.end(), out.begin(), [](char c){ return std::tolower(c); });
    return out;
}

OverlayImpl::Overlay* OverlayImpl::storeNewOverlay(const std::string& key)
{
    if (overlaysKeyLookup.contains(stringToLowercase(key)))
    {
        return nullptr;
    }
    static uint64_t nextOverlayHandle = 1;
    uint64_t handle = nextOverlayHandle++;
    overlays.emplace(handle, Overlay {.handle = handle, .key = key});
    Overlay& overlay = overlays.at(handle);
    overlaysKeyLookup[stringToLowercase(key)] = &overlay;
    TRACE_F("stored overlay %s %lu", key.c_str(), handle);
    return &overlay;
}

OverlayImpl::Overlay* OverlayImpl::getOverlay(uint64_t handle)
{
    auto it = overlays.find(handle);
    if (it == overlays.end())
    {
        return nullptr;
    }
    return &it->second;
}

OverlayImpl::Overlay* OverlayImpl::lookupOverlay(const std::string& key)
{
    auto it = overlaysKeyLookup.find(stringToLowercase(key));
    if (it == overlaysKeyLookup.end())
    {
        return nullptr;
    }
    return it->second;
}

bool OverlayImpl::removeOverlay(uint64_t handle)
{
    auto it = overlays.find(handle);
    if (it == overlays.end())
    {
        return false;
    }
    TRACE_F("removed overlay %s %lu", it->second.key.c_str(), handle);
    overlaysKeyLookup.erase(stringToLowercase(it->second.key));
    overlays.erase(it);
    return true;
}

void OverlayImpl::Overlay::syncFlagsToWindow()
{
    // TODO
}

void OverlayImpl::Overlay::syncFlagsFromWindow()
{
    // TODO
}
