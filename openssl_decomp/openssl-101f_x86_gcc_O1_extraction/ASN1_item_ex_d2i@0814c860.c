
int ASN1_item_ex_d2i(ASN1_VALUE **pval,uchar **in,long len,ASN1_ITEM *it,int tag,int aclass,char opt
                    ,ASN1_TLC *ctx)

{
  byte bVar1;
  int iVar2;
  int in_GS_OFFSET;
  undefined4 uVar3;
  
  if (pval != (ASN1_VALUE **)0x0) {
    if (it->funcs == (void *)0x0) {
      bVar1 = it->itype;
      uVar3 = 0;
    }
    else {
      bVar1 = it->itype;
      uVar3 = *(undefined4 *)((int)it->funcs + 0x10);
    }
    if (bVar1 < 7) {
                    /* WARNING: Could not recover jumptable at 0x0814c8bc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      iVar2 = (*(code *)(&PTR_LAB_082280f8)[(byte)it->itype])(in,uVar3);
      return iVar2;
    }
  }
  if (*(int *)(in_GS_OFFSET + 0x14) == *(int *)(in_GS_OFFSET + 0x14)) {
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(ctx,in);
}

