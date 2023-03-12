
undefined4 ssl_new(int param_1)

{
  void *pvVar1;
  
  pvVar1 = CRYPTO_malloc(0x18,"bio_ssl.c",0x6a);
  if (pvVar1 != (void *)0x0) {
    (*(code *)PTR_memset_006a99f4)(pvVar1,0,0x18);
    *(void **)(param_1 + 0x20) = pvVar1;
    *(undefined4 *)(param_1 + 0xc) = 0;
    *(undefined4 *)(param_1 + 0x14) = 0;
    return 1;
  }
  (*(code *)PTR_ERR_put_error_006a7f34)(0x20,0x76,0x41,"bio_ssl.c",0x6c);
  return 0;
}

