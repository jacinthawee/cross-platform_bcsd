
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

UI * UI_new(void)

{
  UI_METHOD **obj;
  
  obj = (UI_METHOD **)CRYPTO_malloc(0x18,"ui_lib.c",0x50);
  if (obj == (UI_METHOD **)0x0) {
    ERR_put_error(0x28,0x68,0x41,"ui_lib.c",0x53);
  }
  else {
    if (default_UI_meth == (UI_METHOD *)0x0) {
      default_UI_meth = UI_OpenSSL();
    }
    *obj = default_UI_meth;
    obj[1] = (UI_METHOD *)0x0;
    obj[2] = (UI_METHOD *)0x0;
    obj[5] = (UI_METHOD *)0x0;
    CRYPTO_new_ex_data(0xb,obj,(CRYPTO_EX_DATA *)(obj + 3));
  }
  return (UI *)obj;
}

