
char * UI_get0_result(UI *ui,int i)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  if (i < 0) {
    uVar4 = 0x67;
    uVar3 = 0x1ba;
  }
  else {
    iVar1 = (*(code *)PTR_sk_num_006a6e2c)(*(undefined4 *)(ui + 4));
    if (i < iVar1) {
      piVar2 = (int *)(*(code *)PTR_sk_value_006a6e24)(*(undefined4 *)(ui + 4),i);
      if ((piVar2 != (int *)0x0) && (*piVar2 - 1U < 2)) {
        return (char *)piVar2[3];
      }
      return (char *)0x0;
    }
    uVar4 = 0x66;
    uVar3 = 0x1be;
  }
  (*(code *)PTR_ERR_put_error_006a7f34)(0x28,0x6b,uVar4,"ui_lib.c",uVar3);
  return (char *)0x0;
}

