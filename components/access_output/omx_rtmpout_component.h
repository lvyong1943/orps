#ifndef _OMX_RTMPOUT_COMPONENT_H_
#define _OMX_RTMPOUT_COMPONENT_H_

#ifdef _cplusplus
extern "C" {
#endif

#include <OMX_Types.h>
#include <OMX_Component.h>
#include <OMX_Core.h>
#include <omx_base_sink.h>
#include <librtmp/rtmp.h>
#include <xmedia.h>
#include <xutil.h>

#define RTMPOUT_COMP_NAME "OMX.st.rtmpout"
#define RTMPOUT_COMP_ROLE "rtmpout"
#define MAX_RTMPOUT_COMPONENTS 1

DERIVEDCLASS(omx_rtmpout_component_PrivateType, omx_base_sink_PrivateType)
#define omx_rtmpout_component_PrivateType_FIELDS omx_base_sink_PrivateType_FIELDS \
  OMX_STRING output_url; \
  RTMP *rtmp; \
  OMX_BOOL rtmp_ready; \
  xmedia::AVCDecorderConfigurationRecord *avc_dcr; \
  xmedia::AudioSpecificConfig *asc; \
  xutil::MemHolder *mholder; \
  tsem_t *rtmp_sync_sem;
ENDCLASS(omx_rtmpout_component_PrivateType)

OMX_ERRORTYPE omx_rtmpout_component_Constructor(OMX_COMPONENTTYPE *omx_comp, OMX_STRING comp_name);
OMX_ERRORTYPE omx_rtmpout_component_Destructor(OMX_COMPONENTTYPE *omx_comp);
OMX_ERRORTYPE omx_rtmpout_component_MessageHandler(OMX_COMPONENTTYPE *omx_comp, internalRequestMessageType *message);
OMX_ERRORTYPE omx_rtmpout_component_Init(OMX_COMPONENTTYPE *omx_comp);
OMX_ERRORTYPE omx_rtmpout_component_Deinit(OMX_COMPONENTTYPE *omx_comp);

void omx_rtmpout_component_BufferMgmtCallback(
    OMX_COMPONENTTYPE *omx_comp,
    OMX_BUFFERHEADERTYPE *input_buffer);

OMX_ERRORTYPE omx_rtmpout_component_SetParameter(
    OMX_IN OMX_HANDLETYPE hcomp,
    OMX_IN OMX_INDEXTYPE param_index,
    OMX_IN OMX_PTR comp_param);

OMX_ERRORTYPE omx_rtmpout_component_GetParameter(
    OMX_IN OMX_HANDLETYPE hcomp,
    OMX_IN OMX_INDEXTYPE param_index,
    OMX_INOUT OMX_PTR comp_param);

OMX_ERRORTYPE omx_rtmpout_component_GetExtensionIndex(
    OMX_IN OMX_HANDLETYPE hcomp,
    OMX_IN OMX_STRING param_name,
    OMX_OUT OMX_INDEXTYPE *index);

#ifdef _cplusplus
}
#endif

#endif /* end of _OMX_RTMPOUT_COMPONENT_H_ */
