
size_t EC_POINT_point2oct(EC_GROUP *group,EC_POINT *p,point_conversion_form_t form,uchar *buf,
                         size_t len,BN_CTX *ctx)

{
  uint *puVar1;
  undefined4 uVar2;
  size_t sVar3;
  uint uVar4;
  undefined4 uVar5;
  code *UNRECOVERED_JUMPTABLE;
  
  puVar1 = *(uint **)group;
  if ((code *)puVar1[0x14] == (code *)0x0) {
    if ((*puVar1 & 1) == 0) {
      uVar5 = 0x42;
      uVar2 = 0x8a;
      goto LAB_0050d5a0;
    }
    if (puVar1 == *(uint **)p) {
      uVar4 = puVar1[1];
      goto LAB_0050d5d4;
    }
  }
  else if (puVar1 == *(uint **)p) {
    if ((*puVar1 & 1) == 0) {
                    /* WARNING: Could not recover jumptable at 0x0050d63c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      sVar3 = (*(code *)puVar1[0x14])();
      return sVar3;
    }
    uVar4 = puVar1[1];
LAB_0050d5d4:
    UNRECOVERED_JUMPTABLE = (code *)PTR_ec_GFp_simple_point2oct_006a97f0;
    if (uVar4 != 0x196) {
      UNRECOVERED_JUMPTABLE = (code *)PTR_ec_GF2m_simple_point2oct_006a97ec;
    }
                    /* WARNING: Could not recover jumptable at 0x0050d600. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    sVar3 = (*UNRECOVERED_JUMPTABLE)(group,p,form,buf);
    return sVar3;
  }
  uVar5 = 0x65;
  uVar2 = 0x8f;
LAB_0050d5a0:
  (*(code *)PTR_ERR_put_error_006a9030)(0x10,0x7b,uVar5,"ec_oct.c",uVar2);
  return 0;
}

