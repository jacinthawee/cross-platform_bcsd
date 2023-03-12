
int EC_POINT_oct2point(EC_GROUP *group,EC_POINT *p,uchar *buf,size_t len,BN_CTX *ctx)

{
  uint *puVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  code *UNRECOVERED_JUMPTABLE;
  
  puVar1 = *(uint **)group;
  if ((code *)puVar1[0x15] == (code *)0x0) {
    if ((*puVar1 & 1) == 0) {
      uVar5 = 0x42;
      uVar2 = 0xad;
      goto LAB_0050d6ac;
    }
    if (puVar1 == *(uint **)p) {
      uVar4 = puVar1[1];
      goto LAB_0050d6e0;
    }
  }
  else if (puVar1 == *(uint **)p) {
    if ((*puVar1 & 1) == 0) {
                    /* WARNING: Could not recover jumptable at 0x0050d740. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      iVar3 = (*(code *)puVar1[0x15])();
      return iVar3;
    }
    uVar4 = puVar1[1];
LAB_0050d6e0:
    UNRECOVERED_JUMPTABLE = (code *)PTR_ec_GFp_simple_oct2point_006a97f8;
    if (uVar4 != 0x196) {
      UNRECOVERED_JUMPTABLE = (code *)PTR_ec_GF2m_simple_oct2point_006a97f4;
    }
                    /* WARNING: Could not recover jumptable at 0x0050d708. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar3 = (*UNRECOVERED_JUMPTABLE)(group,p,buf,len);
    return iVar3;
  }
  uVar5 = 0x65;
  uVar2 = 0xb2;
LAB_0050d6ac:
  (*(code *)PTR_ERR_put_error_006a9030)(0x10,0x7a,uVar5,"ec_oct.c",uVar2);
  return 0;
}

