
X509_ALGOR * PKCS5_pbe_set(int alg,int iter,uchar *salt,int saltlen)

{
  undefined *puVar1;
  int *piVar2;
  uint uVar3;
  X509_ALGOR *pXVar4;
  ASN1_STRING **val;
  int iVar5;
  undefined4 uVar6;
  uchar *puVar7;
  undefined1 *aobj;
  ASN1_STRING *local_30;
  int local_2c;
  long v;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  pXVar4 = X509_ALGOR_new();
  if (pXVar4 == (X509_ALGOR *)0x0) {
    aobj = &DAT_000000ca;
    (*(code *)PTR_ERR_put_error_006a9030)(0xd,0xca,0x41,"p5_pbe.c",0x8b);
    pXVar4 = (X509_ALGOR *)0x0;
    goto LAB_0056ccd0;
  }
  local_30 = (ASN1_STRING *)0x0;
  val = (ASN1_STRING **)ASN1_item_new((ASN1_ITEM *)PBEPARAM_it);
  if (val == (ASN1_STRING **)0x0) {
    aobj = (undefined1 *)0xd7;
    (*(code *)PTR_ERR_put_error_006a9030)(0xd,0xd7,0x41,"p5_pbe.c",0x57);
  }
  else {
    v = 0x800;
    if (0 < iter) {
      v = iter;
    }
    iVar5 = ASN1_INTEGER_set(val[1],v);
    if (iVar5 == 0) {
      uVar6 = 0x5e;
LAB_0056cc7c:
      (*(code *)PTR_ERR_put_error_006a9030)(0xd,0xd7,0x41,"p5_pbe.c",uVar6);
    }
    else {
      if (saltlen == 0) {
        saltlen = 8;
      }
      iVar5 = ASN1_STRING_set(*val,(void *)0x0,saltlen);
      if (iVar5 == 0) {
        uVar6 = 0x65;
        goto LAB_0056cc7c;
      }
      puVar7 = ASN1_STRING_data(*val);
      if (salt != (uchar *)0x0) {
        (*(code *)PTR_memcpy_006aabf4)(puVar7,salt,saltlen);
LAB_0056cd34:
        iVar5 = (*(code *)PTR_ASN1_item_pack_006a9f14)(val,PBEPARAM_it,&local_30);
        if (iVar5 != 0) {
          ASN1_item_free((ASN1_VALUE *)val,(ASN1_ITEM *)PBEPARAM_it);
          aobj = (undefined1 *)(*(code *)PTR_OBJ_nid2obj_006a8240)(alg);
          iVar5 = X509_ALGOR_set0(pXVar4,(ASN1_OBJECT *)aobj,0x10,local_30);
          if (iVar5 != 0) goto LAB_0056ccd0;
          goto LAB_0056cca4;
        }
        uVar6 = 0x70;
        goto LAB_0056cc7c;
      }
      iVar5 = (*(code *)PTR_RAND_pseudo_bytes_006a8664)(puVar7,saltlen);
      if (-1 < iVar5) goto LAB_0056cd34;
    }
    aobj = PBEPARAM_it;
    ASN1_item_free((ASN1_VALUE *)val,(ASN1_ITEM *)PBEPARAM_it);
  }
LAB_0056cca4:
  if (local_30 != (ASN1_STRING *)0x0) {
    ASN1_STRING_free(local_30);
  }
  X509_ALGOR_free(pXVar4);
  pXVar4 = (X509_ALGOR *)0x0;
LAB_0056ccd0:
  if (local_2c == *(int *)puVar1) {
    return pXVar4;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  piVar2 = *(int **)PTR___stack_chk_guard_006aabf0;
  uVar3 = (uint)PBE2PARAM_it[0];
  if (PBE2PARAM_it._16_4_ == 0) {
    if (uVar3 < 7) {
                    /* WARNING: Could not recover jumptable at 0x00565630. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      pXVar4 = (X509_ALGOR *)(*(code *)(&switchD_00565630::switchdataD_0066abc0)[uVar3])();
      return pXVar4;
    }
  }
  else if (uVar3 < 7) {
                    /* WARNING: Could not recover jumptable at 0x005651a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    pXVar4 = (X509_ALGOR *)(*(code *)(&switchD_005651a0::switchdataD_0066aba4)[uVar3])();
    return pXVar4;
  }
  if (piVar2 == *(int **)PTR___stack_chk_guard_006aabf0) {
    return (X509_ALGOR *)0x0;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  return *(X509_ALGOR **)(*piVar2 + (int)*(char ***)((int)aobj + 4));
}

