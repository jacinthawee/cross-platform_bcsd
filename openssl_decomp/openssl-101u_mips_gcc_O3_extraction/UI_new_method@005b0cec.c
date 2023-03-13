
UI * UI_new_method(UI_METHOD *method)

{
  undefined *puVar1;
  UI_METHOD **ppUVar2;
  
  ppUVar2 = (UI_METHOD **)(*(code *)PTR_CRYPTO_malloc_006a7008)(0x18,"ui_lib.c",0x51);
  if (ppUVar2 == (UI_METHOD **)0x0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0x28,0x68,0x41,"ui_lib.c",0x53);
    ppUVar2 = (UI_METHOD **)0x0;
  }
  else {
    if (method == (UI_METHOD *)0x0) {
      if (default_UI_meth == (UI_METHOD *)0x0) {
        default_UI_meth = UI_OpenSSL();
        *ppUVar2 = default_UI_meth;
      }
      else {
        *ppUVar2 = default_UI_meth;
      }
    }
    else {
      *ppUVar2 = method;
    }
    puVar1 = PTR_CRYPTO_new_ex_data_006a8314;
    ppUVar2[1] = (UI_METHOD *)0x0;
    ppUVar2[2] = (UI_METHOD *)0x0;
    ppUVar2[5] = (UI_METHOD *)0x0;
    (*(code *)puVar1)(0xb,ppUVar2,ppUVar2 + 3);
  }
  return (UI *)ppUVar2;
}

