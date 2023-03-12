
int SSL_COMP_add_compression_method(int id,COMP_METHOD *cm)

{
  int *ptr;
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  if ((cm == (COMP_METHOD *)0x0) || (cm->type == 0)) {
    return 1;
  }
  if (0x3e < id - 0xc1U) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0xa5,0x133,"ssl_ciph.c",0x755);
    return 0;
  }
  CRYPTO_mem_ctrl(3);
  ptr = (int *)CRYPTO_malloc(0xc,"ssl_ciph.c",0x75a);
  ptr[2] = (int)cm;
  *ptr = id;
  load_builtin_compressions();
  if (ssl_comp_methods != 0) {
    iVar1 = (*(code *)PTR_sk_find_006a8044)(ssl_comp_methods,ptr);
    if (-1 < iVar1) {
      CRYPTO_free(ptr);
      CRYPTO_mem_ctrl(2);
      uVar3 = 0x135;
      uVar2 = 0x762;
      goto LAB_004b30b4;
    }
    if ((ssl_comp_methods != 0) &&
       (iVar1 = (*(code *)PTR_sk_push_006a6fa8)(ssl_comp_methods,ptr), iVar1 != 0)) {
      CRYPTO_mem_ctrl(2);
      return 0;
    }
  }
  CRYPTO_free(ptr);
  CRYPTO_mem_ctrl(2);
  uVar3 = 0x41;
  uVar2 = 0x768;
LAB_004b30b4:
  (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0xa5,uVar3,"ssl_ciph.c",uVar2);
  return 1;
}

