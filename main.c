#include "cyhal.h"
#include "cybsp.h"
#include "cy_pdl.h"
#include "GUI.h"
#include "SPI_st7789v.h"
#include "LCDConf.h"

const SPI_st7789v_pins_t tft_pins =
{
    .MOSI = P10_0,
    .MISO = P10_1,
    .SCK = P10_2,
    .SS = P10_3,
    .dc = P9_7,
	.rst= P9_4,
	.frec= 25000000
};

int main(void)
{
    cy_rslt_t result;

#if defined (CY_DEVICE_SECURE)
    cyhal_wdt_t wdt_obj;

    /* Clear watchdog timer so that it doesn't trigger a reset */
    result = cyhal_wdt_init(&wdt_obj, cyhal_wdt_get_max_timeout_ms());
    CY_ASSERT(CY_RSLT_SUCCESS == result);
    cyhal_wdt_free(&wdt_obj);
#endif

    /* Initialize the device and board peripherals */
    result = cybsp_init();

    /* Board init failed. Stop program execution */
    if (result != CY_RSLT_SUCCESS)
    {
        CY_ASSERT(0);
    }

    /* Enable global interrupts */
    __enable_irq();

    result = SPI_st7789v_init8(&tft_pins);
    CY_ASSERT(result == CY_RSLT_SUCCESS);

    GUI_Init();
    GUI_SetBkColor(GUI_WHITE);
    GUI_Clear();
    GUI_SetColor(GUI_BLACK);
    GUI_SetFont(&GUI_Font32B_ASCII);
    GUI_DispStringHCenterAt("TECNICAS", 120, 8);
    GUI_DispStringHCenterAt("DIGITALES II", 120, 32);

    while(1){
    	//Infinte loop...
    }
}

