#include "scePspNpDrm_user.h"

#include "Core/HLE/HLE.h"
#include "Core/HLE/FunctionWrappers.h"
#include "Core/HLE/sceIo.h"

static int sceNpDrmSetLicenseeKey(u32 npDrmKeyAddr)
{
	INFO_LOG(HLE, "call sceNpDrmSetLicenseeKey(%08x)", npDrmKeyAddr);
	return 0;
}

static int sceNpDrmClearLicenseeKey()
{
	INFO_LOG(HLE, "call sceNpDrmClearLicenseeKey()");
	return 0;
}

static int sceNpDrmRenameCheck(const char *filename)
{
	INFO_LOG(HLE, "call sceNpDrmRenameCheck(%s)", filename);
	return 0;
}

static int sceNpDrmEdataSetupKey(u32 edataFd)
{
	INFO_LOG(HLE, "call sceNpDrmEdataSetupKey %x", edataFd);
	/* set PGD offset */
	sceIoIoctl(edataFd, 0x04100002, 0x90, 0, 0, 0);
	/* call PGD open */
	return sceIoIoctl(edataFd, 0x04100001, 0, 0, 0, 0);
}

static int sceNpDrmEdataGetDataSize(u32 edataFd)
{
	INFO_LOG(HLE, "call sceNpDrmEdataGetDataSize %x", edataFd);
	return sceIoIoctl(edataFd, 0x04100010, 0, 0, 0, 0);
}

static int sceNpDrmOpen()
{
	ERROR_LOG(HLE, "UNIMPL sceNpDrmOpen");
	return 0;
}

const HLEFunction sceNpDrm[] =
{ 
	{0xA1336091, WrapI_U<sceNpDrmSetLicenseeKey>, "sceNpDrmSetLicenseeKey"},
	{0x9B745542, WrapI_V<sceNpDrmClearLicenseeKey>, "sceNpDrmClearLicenseeKey"},
	{0x275987D1, WrapI_C<sceNpDrmRenameCheck>, "sceNpDrmRenameCheck"},
	{0x08d98894, WrapI_U<sceNpDrmEdataSetupKey>, "sceNpDrmEdataSetupKey"},
	{0x219EF5CC, WrapI_U<sceNpDrmEdataGetDataSize>, "sceNpDrmEdataGetDataSize"},
	{0x2BAA4294, WrapI_V<sceNpDrmOpen>, "sceNpDrmOpen"},
};

void Register_sceNpDrm()
{
	RegisterModule("sceNpDrm", ARRAY_SIZE(sceNpDrm), sceNpDrm);
	RegisterModule("scePspNpDrm_user", ARRAY_SIZE(sceNpDrm), sceNpDrm);
}
 
