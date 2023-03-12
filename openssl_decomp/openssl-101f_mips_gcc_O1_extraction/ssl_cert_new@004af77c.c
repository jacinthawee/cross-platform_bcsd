
int * ssl_cert_new(void)

{
  undefined *puVar1;
  int *piVar2;
  int iVar3;
  
  piVar2 = (int *)CRYPTO_malloc(0x94,"ssl_cert.c",0xb6);
  if (piVar2 == (int *)0x0) {
    (*(code *)PTR_ERR_put_error_006a9030)(0x14,0xa2,0x41,"ssl_cert.c",0xb9);
    piVar2 = (int *)0x0;
  }
  else {
    (*(code *)PTR_memset_006aab00)(piVar2,0,0x94);
    piVar2[0x24] = 1;
    puVar1 = PTR_EVP_sha1_006a86c4;
    *piVar2 = (int)(piVar2 + 0xc);
    iVar3 = (*(code *)puVar1)();
    puVar1 = PTR_EVP_sha1_006a86c4;
    piVar2[0x14] = iVar3;
    iVar3 = (*(code *)puVar1)();
    puVar1 = PTR_EVP_sha1_006a86c4;
    piVar2[0x11] = iVar3;
    iVar3 = (*(code *)puVar1)();
    puVar1 = PTR_EVP_sha1_006a86c4;
    piVar2[0xe] = iVar3;
    iVar3 = (*(code *)puVar1)();
    piVar2[0x1d] = iVar3;
  }
  return piVar2;
}

