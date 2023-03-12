
int PKCS5_pbe_set0_algor(X509_ALGOR *algor,int alg,int iter,uchar *salt,int saltlen)

{
  undefined *puVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  X509_ALGOR *alg_00;
  ASN1_STRING **val;
  int iVar6;
  undefined4 uVar7;
  uchar *puVar8;
  undefined1 *puVar9;
  ASN1_STRING **unaff_s0;
  char *len;
  code *pcVar10;
  ASN1_STRING *pAStack_80;
  int iStack_7c;
  ASN1_STRING **ppAStack_74;
  int iStack_70;
  undefined *puStack_6c;
  undefined4 uStack_68;
  int iStack_64;
  uchar *puStack_60;
  X509_ALGOR *pXStack_5c;
  int iStack_58;
  code *pcStack_54;
  undefined4 local_40;
  undefined *local_38;
  ASN1_STRING *local_30;
  int local_2c;
  long v;
  ASN1_OBJECT *v_00;
  
  puStack_6c = PTR___stack_chk_guard_006aabf0;
  local_38 = &_gp;
  local_30 = (ASN1_STRING *)0x0;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  len = (char *)salt;
  ppAStack_74 = (ASN1_STRING **)ASN1_item_new((ASN1_ITEM *)PBEPARAM_it);
  if (ppAStack_74 == (ASN1_STRING **)0x0) {
    iVar4 = 0x41;
    len = "p5_pbe.c";
    local_40 = 0x57;
    puVar9 = (undefined1 *)0xd7;
    (**(code **)(local_38 + -0x6eb0))(0xd);
LAB_0056ca1c:
    ppAStack_74 = unaff_s0;
    if (local_30 == (ASN1_STRING *)0x0) {
      iVar5 = 0;
    }
    else {
      ASN1_STRING_free(local_30);
      iVar5 = 0;
    }
  }
  else {
    v = 0x800;
    if (0 < iter) {
      v = iter;
    }
    iVar4 = ASN1_INTEGER_set(ppAStack_74[1],v);
    unaff_s0 = ppAStack_74;
    if (iVar4 == 0) {
      pcVar10 = *(code **)(local_38 + -0x6eb0);
      local_40 = 0x5e;
LAB_0056c9f4:
      len = "p5_pbe.c";
      iVar4 = 0x41;
      (*pcVar10)(0xd,0xd7);
LAB_0056ca0c:
      puVar9 = PBEPARAM_it;
      ASN1_item_free((ASN1_VALUE *)ppAStack_74,(ASN1_ITEM *)PBEPARAM_it);
      goto LAB_0056ca1c;
    }
    if (saltlen == 0) {
      saltlen = 8;
    }
    iVar4 = saltlen;
    iVar5 = ASN1_STRING_set(*ppAStack_74,(void *)0x0,saltlen);
    if (iVar5 == 0) {
      pcVar10 = *(code **)(local_38 + -0x6eb0);
      local_40 = 0x65;
      goto LAB_0056c9f4;
    }
    puVar8 = ASN1_STRING_data(*ppAStack_74);
    if (salt == (uchar *)0x0) {
      iVar5 = (**(code **)(local_38 + -0x787c))(puVar8,saltlen);
      if (-1 < iVar5) goto LAB_0056ca9c;
      goto LAB_0056ca0c;
    }
    (**(code **)(local_38 + -0x52ec))(puVar8,salt,saltlen);
LAB_0056ca9c:
    iVar4 = (**(code **)(local_38 + -0x5fcc))(ppAStack_74,PBEPARAM_it,&local_30);
    if (iVar4 == 0) {
      pcVar10 = *(code **)(local_38 + -0x6eb0);
      local_40 = 0x70;
      goto LAB_0056c9f4;
    }
    ASN1_item_free((ASN1_VALUE *)ppAStack_74,(ASN1_ITEM *)PBEPARAM_it);
    puVar9 = (undefined1 *)(**(code **)(local_38 + -0x7ca0))(alg);
    iVar4 = 0x10;
    len = (char *)local_30;
    iVar5 = X509_ALGOR_set0(algor,(ASN1_OBJECT *)puVar9,0x10,local_30);
    if (iVar5 == 0) goto LAB_0056ca1c;
    iVar5 = 1;
  }
  if (local_2c == *(int *)puStack_6c) {
    return iVar5;
  }
  pcStack_54 = PKCS5_pbe_set;
  iVar5 = local_2c;
  (**(code **)(local_38 + -0x5328))();
  puVar1 = PTR___stack_chk_guard_006aabf0;
  uStack_68 = 0x690000;
  iStack_7c = *(int *)PTR___stack_chk_guard_006aabf0;
  iStack_70 = saltlen;
  iStack_64 = iter;
  puStack_60 = salt;
  pXStack_5c = algor;
  iStack_58 = alg;
  alg_00 = X509_ALGOR_new();
  if (alg_00 == (X509_ALGOR *)0x0) {
    puVar9 = &DAT_000000ca;
    (*(code *)PTR_ERR_put_error_006a9030)(0xd,0xca,0x41,"p5_pbe.c",0x8b);
    alg_00 = (X509_ALGOR *)0x0;
    goto LAB_0056ccd0;
  }
  pAStack_80 = (ASN1_STRING *)0x0;
  val = (ASN1_STRING **)ASN1_item_new((ASN1_ITEM *)PBEPARAM_it);
  if (val == (ASN1_STRING **)0x0) {
    puVar9 = (undefined1 *)0xd7;
    (*(code *)PTR_ERR_put_error_006a9030)(0xd,0xd7,0x41,"p5_pbe.c",0x57);
  }
  else {
    v_00 = (ASN1_OBJECT *)&DAT_00000800;
    if (0 < (int)puVar9) {
      v_00 = (ASN1_OBJECT *)puVar9;
    }
    iVar6 = ASN1_INTEGER_set(val[1],(long)v_00);
    if (iVar6 == 0) {
      uVar7 = 0x5e;
LAB_0056cc7c:
      (*(code *)PTR_ERR_put_error_006a9030)(0xd,0xd7,0x41,"p5_pbe.c",uVar7);
    }
    else {
      if ((ASN1_STRING *)len == (ASN1_STRING *)0x0) {
        len = &DAT_00000008;
      }
      iVar6 = ASN1_STRING_set(*val,(void *)0x0,(int)len);
      if (iVar6 == 0) {
        uVar7 = 0x65;
        goto LAB_0056cc7c;
      }
      puVar8 = ASN1_STRING_data(*val);
      if (iVar4 != 0) {
        (*(code *)PTR_memcpy_006aabf4)(puVar8,iVar4,len);
LAB_0056cd34:
        iVar4 = (*(code *)PTR_ASN1_item_pack_006a9f14)(val,PBEPARAM_it,&pAStack_80);
        if (iVar4 != 0) {
          ASN1_item_free((ASN1_VALUE *)val,(ASN1_ITEM *)PBEPARAM_it);
          puVar9 = (undefined1 *)(*(code *)PTR_OBJ_nid2obj_006a8240)(iVar5);
          iVar4 = X509_ALGOR_set0(alg_00,(ASN1_OBJECT *)puVar9,0x10,pAStack_80);
          if (iVar4 != 0) goto LAB_0056ccd0;
          goto LAB_0056cca4;
        }
        uVar7 = 0x70;
        goto LAB_0056cc7c;
      }
      iVar4 = (*(code *)PTR_RAND_pseudo_bytes_006a8664)(puVar8,len);
      if (-1 < iVar4) goto LAB_0056cd34;
    }
    puVar9 = PBEPARAM_it;
    ASN1_item_free((ASN1_VALUE *)val,(ASN1_ITEM *)PBEPARAM_it);
  }
LAB_0056cca4:
  if (pAStack_80 != (ASN1_STRING *)0x0) {
    ASN1_STRING_free(pAStack_80);
  }
  X509_ALGOR_free(alg_00);
  alg_00 = (X509_ALGOR *)0x0;
LAB_0056ccd0:
  if (iStack_7c == *(int *)puVar1) {
    return (int)alg_00;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  piVar2 = *(int **)PTR___stack_chk_guard_006aabf0;
  uVar3 = (uint)PBE2PARAM_it[0];
  if (PBE2PARAM_it._16_4_ == 0) {
    if (uVar3 < 7) {
                    /* WARNING: Could not recover jumptable at 0x00565630. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      iVar4 = (*(code *)(&switchD_00565630::switchdataD_0066abc0)[uVar3])();
      return iVar4;
    }
  }
  else if (uVar3 < 7) {
                    /* WARNING: Could not recover jumptable at 0x005651a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar4 = (*(code *)(&switchD_005651a0::switchdataD_0066aba4)[uVar3])();
    return iVar4;
  }
  if (piVar2 == *(int **)PTR___stack_chk_guard_006aabf0) {
    return 0;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  return *(int *)(*piVar2 + (int)*(char ***)((int)puVar9 + 4));
}

