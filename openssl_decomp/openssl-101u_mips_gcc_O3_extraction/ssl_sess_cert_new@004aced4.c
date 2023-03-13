
void * ssl_sess_cert_new(void)

{
  void *pvVar1;
  
  pvVar1 = CRYPTO_malloc(0x7c,"ssl_cert.c",0x18b);
  if (pvVar1 == (void *)0x0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0xe1,0x41,"ssl_cert.c",0x18d);
    pvVar1 = (void *)0x0;
  }
  else {
    (*(code *)PTR_memset_006a99f4)(pvVar1,0,0x7c);
    *(int *)((int)pvVar1 + 8) = (int)pvVar1 + 0xc;
    *(undefined4 *)((int)pvVar1 + 0x78) = 1;
  }
  return pvVar1;
}

