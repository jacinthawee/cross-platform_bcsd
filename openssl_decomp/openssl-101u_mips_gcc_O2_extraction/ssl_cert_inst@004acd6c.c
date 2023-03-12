
undefined4 ssl_cert_inst(int **param_1)

{
  undefined *puVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  
  if (param_1 == (int **)0x0) {
    uVar4 = 0;
    (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0xde,0x43,"ssl_cert.c",0x17b);
  }
  else {
    uVar4 = 1;
    if (*param_1 == (int *)0x0) {
      piVar2 = (int *)CRYPTO_malloc(0x94,"ssl_cert.c",0xb7);
      if (piVar2 == (int *)0x0) {
        uVar4 = 0;
        (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0xa2,0x41,"ssl_cert.c",0xb9);
        *param_1 = (int *)0x0;
        (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0xde,0x41,"ssl_cert.c",0x180);
      }
      else {
        (*(code *)PTR_memset_006a99f4)(piVar2,0,0x94);
        piVar2[0x24] = 1;
        puVar1 = PTR_EVP_sha1_006a75d0;
        *piVar2 = (int)(piVar2 + 0xc);
        iVar3 = (*(code *)puVar1)();
        puVar1 = PTR_EVP_sha1_006a75d0;
        piVar2[0x14] = iVar3;
        iVar3 = (*(code *)puVar1)();
        puVar1 = PTR_EVP_sha1_006a75d0;
        piVar2[0x11] = iVar3;
        iVar3 = (*(code *)puVar1)();
        puVar1 = PTR_EVP_sha1_006a75d0;
        piVar2[0xe] = iVar3;
        iVar3 = (*(code *)puVar1)();
        piVar2[0x1d] = iVar3;
        *param_1 = piVar2;
      }
    }
  }
  return uVar4;
}

