
undefined4 asn1_bio_write(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  
  if (((param_2 != 0) && (-1 < param_3)) && (*(int *)(param_1 + 0x24) != 0)) {
    uVar1 = asn1_bio_write_part_1();
    return uVar1;
  }
  return 0;
}

