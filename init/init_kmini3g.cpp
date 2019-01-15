/*
   Copyright (c) 2013, The Linux Foundation. All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above
      copyright notice, this list of conditions and the following
      disclaimer in the documentation and/or other materials provided
      with the distribution.
    * Neither the name of The Linux Foundation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
   WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
   ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
   BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
   BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
   WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
   OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
   IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdlib.h>

#include "vendor_init.h"
#include "property_service.h"
#include "log.h"
#include "util.h"

#define ISMATCH(a,b)    (!strncmp(a,b,PROP_VALUE_MAX))

void gsm_properties()
{
    property_set("telephony.lteOnGsmDevice", "0");
    property_set("ro.telephony.default_network", "0");
}

void init_variant_properties()
{

    std::string bootloader = property_get("ro.bootloader");

    if (bootloader.find("G800HX")) {
        /* kmini3g */
        property_set("ro.build.fingerprint", "samsung/kmini3gxx/kmini3g:5.1.1/LMY47X/G800HXXU1BOI2:user/release-keys");
        property_set("ro.build.description", "kmini3gxx-user 5.1.1 LMY47X G800HXXU1BOI2 release-keys");
        property_set("ro.product.model", "SM-G800H");
        property_set("ro.product.device", "kmini3g");
        property_set("rild.libpath2", "/system/lib/libsec-ril-dsds.so");
        property_set("persist.radio.multisim.config", "dsds");
        property_set("ro.multisim.set_audio_params", "true");
        property_set("ro.multisim.simslotcount", "2");
        property_set("ro.ril.telephony.mqanelements", "6");
        property_set("ro.telephony.ril_class", "SamsungMSM8226RIL");
        gsm_properties();
    } else if (bootloader.find("G800HQ")) {
        /* kmini3g?? single sim variant */
        property_set("ro.build.fingerprint", "samsung/kmini3gxx/kmini3g:4.4.2/KOT49H/G800HXXU1ANL1:user/release-keys");
        property_set("ro.build.description", "kmini3gxx-user 4.4.2 KOT49H G800HXXU1ANL1 release-keys");
        property_set("ro.product.model", "SM-G800HQ");
        property_set("ro.product.device", "kmini3g??");
        property_set("ro.telephony.ril_class", "SamsungMSM8226RIL");
        gsm_properties();
    }
}
