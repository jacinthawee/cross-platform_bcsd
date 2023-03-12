
undefined4 file_puts(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = (*(code *)PTR_strlen_006aab30)(param_2);
  if ((*(int *)(param_1 + 0xc) != 0) &&
     (iVar2 = (*(code *)PTR_fwrite_006aab7c)(param_2,uVar1,1,*(undefined4 *)(param_1 + 0x20)),
     iVar2 != 0)) {
    return uVar1;
  }
  return 0;
}

