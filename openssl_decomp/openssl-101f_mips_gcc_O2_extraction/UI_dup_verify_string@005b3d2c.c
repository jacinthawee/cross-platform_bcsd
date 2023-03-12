
int UI_dup_verify_string
              (UI *ui,char *prompt,int flags,char *result_buf,int minsize,int maxsize,char *test_buf
              )

{
  undefined *puVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  if (prompt == (char *)0x0) {
    uVar5 = 0x43;
    uVar4 = 0x93;
  }
  else {
    iVar2 = (*(code *)PTR_BUF_strdup_006a80dc)(prompt);
    if (iVar2 == 0) {
      (*(code *)PTR_ERR_put_error_006a9030)(0x28,0x6a,0x41,"ui_lib.c",0x11f);
      return -1;
    }
    if (result_buf != (char *)0x0) {
      piVar3 = (int *)(*(code *)PTR_CRYPTO_malloc_006a8108)(0x20,"ui_lib.c",0x9a);
      if (piVar3 == (int *)0x0) {
        return -1;
      }
      piVar3[1] = iVar2;
      piVar3[3] = (int)result_buf;
      piVar3[2] = flags;
      iVar2 = *(int *)(ui + 4);
      piVar3[7] = 1;
      *piVar3 = 2;
      if (iVar2 == 0) {
        iVar2 = (*(code *)PTR_sk_new_null_006a80a4)();
        *(int *)(ui + 4) = iVar2;
        if (iVar2 == 0) {
          if (((piVar3[7] & 1U) != 0) &&
             ((*(code *)PTR_CRYPTO_free_006a7f88)(piVar3[1]), *piVar3 == 3)) {
            (*(code *)PTR_CRYPTO_free_006a7f88)(piVar3[4]);
            (*(code *)PTR_CRYPTO_free_006a7f88)(piVar3[5]);
            (*(code *)PTR_CRYPTO_free_006a7f88)(piVar3[6]);
          }
          (*(code *)PTR_CRYPTO_free_006a7f88)(piVar3);
          return -1;
        }
      }
      puVar1 = PTR_sk_push_006a80a8;
      piVar3[4] = minsize;
      piVar3[5] = maxsize;
      piVar3[6] = (int)test_buf;
      iVar2 = (*(code *)puVar1)(iVar2,piVar3);
      if (0 < iVar2) {
        return iVar2;
      }
      return iVar2 + -1;
    }
    uVar5 = 0x69;
    uVar4 = 0x98;
  }
  (*(code *)PTR_ERR_put_error_006a9030)(0x28,0x6d,uVar5,"ui_lib.c",uVar4);
  return -1;
}

