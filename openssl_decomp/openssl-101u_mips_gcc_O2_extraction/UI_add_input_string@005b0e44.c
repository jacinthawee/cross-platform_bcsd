
int UI_add_input_string(UI *ui,char *prompt,int flags,char *result_buf,int minsize,int maxsize)

{
  undefined *puVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  
  if (prompt == (char *)0x0) {
    uVar5 = 0x43;
    uVar3 = 0x8f;
  }
  else {
    if (result_buf != (char *)0x0) {
      piVar2 = (int *)(*(code *)PTR_CRYPTO_malloc_006a7008)(0x20,"ui_lib.c",0x93);
      if (piVar2 == (int *)0x0) {
        return -1;
      }
      piVar2[1] = (int)prompt;
      piVar2[3] = (int)result_buf;
      piVar2[7] = 0;
      piVar2[2] = flags;
      iVar4 = *(int *)(ui + 4);
      *piVar2 = 1;
      if (iVar4 == 0) {
        iVar4 = (*(code *)PTR_sk_new_null_006a6fa4)();
        *(int *)(ui + 4) = iVar4;
        if (iVar4 == 0) {
          if (((piVar2[7] & 1U) != 0) &&
             ((*(code *)PTR_CRYPTO_free_006a6e88)(piVar2[1]), *piVar2 == 3)) {
            (*(code *)PTR_CRYPTO_free_006a6e88)(piVar2[4]);
            (*(code *)PTR_CRYPTO_free_006a6e88)(piVar2[5]);
            (*(code *)PTR_CRYPTO_free_006a6e88)(piVar2[6]);
          }
          (*(code *)PTR_CRYPTO_free_006a6e88)(piVar2);
          return -1;
        }
      }
      puVar1 = PTR_sk_push_006a6fa8;
      piVar2[6] = 0;
      piVar2[4] = minsize;
      piVar2[5] = maxsize;
      iVar4 = (*(code *)puVar1)(iVar4,piVar2);
      return iVar4 - (uint)(iVar4 < 1);
    }
    uVar5 = 0x69;
    uVar3 = 0x92;
  }
  (*(code *)PTR_ERR_put_error_006a7f34)(0x28,0x6d,uVar5,"ui_lib.c",uVar3);
  return -1;
}
