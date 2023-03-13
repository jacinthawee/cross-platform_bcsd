
int UI_dup_input_string(UI *ui,char *prompt,int flags,char *result_buf,int minsize,int maxsize)

{
  undefined *puVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  if (prompt == (char *)0x0) {
    uVar5 = 0x43;
    uVar4 = 0x8f;
  }
  else {
    iVar2 = (*(code *)PTR_BUF_strdup_006a6fdc)(prompt);
    if (iVar2 == 0) {
      (*(code *)PTR_ERR_put_error_006a7f34)(0x28,0x67,0x41,"ui_lib.c",0xf9);
      return 0;
    }
    if (result_buf != (char *)0x0) {
      piVar3 = (int *)(*(code *)PTR_CRYPTO_malloc_006a7008)(0x20,"ui_lib.c",0x93);
      if (piVar3 == (int *)0x0) {
        return -1;
      }
      piVar3[1] = iVar2;
      piVar3[3] = (int)result_buf;
      piVar3[2] = flags;
      piVar3[7] = 1;
      *piVar3 = 1;
      iVar2 = *(int *)(ui + 4);
      if (iVar2 == 0) {
        iVar2 = (*(code *)PTR_sk_new_null_006a6fa4)();
        *(int *)(ui + 4) = iVar2;
        if (iVar2 == 0) {
          if (((piVar3[7] & 1U) != 0) &&
             ((*(code *)PTR_CRYPTO_free_006a6e88)(piVar3[1]), *piVar3 == 3)) {
            (*(code *)PTR_CRYPTO_free_006a6e88)(piVar3[4]);
            (*(code *)PTR_CRYPTO_free_006a6e88)(piVar3[5]);
            (*(code *)PTR_CRYPTO_free_006a6e88)(piVar3[6]);
          }
          (*(code *)PTR_CRYPTO_free_006a6e88)(piVar3);
          return -1;
        }
      }
      puVar1 = PTR_sk_push_006a6fa8;
      piVar3[6] = 0;
      piVar3[4] = minsize;
      piVar3[5] = maxsize;
      iVar2 = (*(code *)puVar1)(iVar2,piVar3);
      if (0 < iVar2) {
        return iVar2;
      }
      return iVar2 + -1;
    }
    uVar5 = 0x69;
    uVar4 = 0x92;
  }
  (*(code *)PTR_ERR_put_error_006a7f34)(0x28,0x6d,uVar5,"ui_lib.c",uVar4);
  return -1;
}

