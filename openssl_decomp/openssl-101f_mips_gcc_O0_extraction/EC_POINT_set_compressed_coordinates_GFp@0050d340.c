
int EC_POINT_set_compressed_coordinates_GFp
              (EC_GROUP *group,EC_POINT *p,BIGNUM *x,int y_bit,BN_CTX *ctx)

{
  uint *puVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  code *UNRECOVERED_JUMPTABLE;
  
  puVar1 = *(uint **)group;
  if ((code *)puVar1[0x13] == (code *)0x0) {
    if ((*puVar1 & 1) == 0) {
      uVar5 = 0x42;
      uVar2 = 0x4d;
      goto LAB_0050d394;
    }
    if (puVar1 == *(uint **)p) {
      uVar4 = puVar1[1];
      goto LAB_0050d3c8;
    }
  }
  else if (puVar1 == *(uint **)p) {
    if ((*puVar1 & 1) == 0) {
                    /* WARNING: Could not recover jumptable at 0x0050d428. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      iVar3 = (*(code *)puVar1[0x13])();
      return iVar3;
    }
    uVar4 = puVar1[1];
LAB_0050d3c8:
    UNRECOVERED_JUMPTABLE = (code *)PTR_ec_GFp_simple_set_compressed_coordinates_006a97e8;
    if (uVar4 != 0x196) {
      UNRECOVERED_JUMPTABLE = (code *)PTR_ec_GF2m_simple_set_compressed_coordinates_006a97e4;
    }
                    /* WARNING: Could not recover jumptable at 0x0050d3f0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar3 = (*UNRECOVERED_JUMPTABLE)(group,p,x,y_bit);
    return iVar3;
  }
  uVar5 = 0x65;
  uVar2 = 0x52;
LAB_0050d394:
  (*(code *)PTR_ERR_put_error_006a9030)(0x10,0x7d,uVar5,"ec_oct.c",uVar2);
  return 0;
}

