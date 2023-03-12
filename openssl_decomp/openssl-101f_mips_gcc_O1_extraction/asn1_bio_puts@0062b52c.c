
undefined4 asn1_bio_puts(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = (*(code *)PTR_strlen_006aab30)(param_2);
  if ((-1 < iVar1) && (*(int *)(param_1 + 0x24) != 0)) {
    uVar2 = asn1_bio_write_part_1(param_1,param_2,iVar1);
    return uVar2;
  }
  return 0;
}

