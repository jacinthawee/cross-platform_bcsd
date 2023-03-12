
int ASN1_item_i2d(ASN1_VALUE *val,uchar **out,ASN1_ITEM *it)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  ASN1_VALUE *length;
  uchar *puVar4;
  uchar *puVar5;
  undefined4 uVar6;
  uint extraout_v1;
  ASN1_VALUE **pval;
  char *out_00;
  ASN1_VALUE **pval_00;
  ASN1_VALUE *pAVar7;
  uchar **aclass;
  int unaff_s2;
  uchar **ppuVar8;
  ASN1_ITEM *it_00;
  ASN1_VALUE **unaff_s4;
  uchar *unaff_s5;
  int iVar9;
  int iStack_a4;
  uchar **ppuStack_a0;
  ASN1_VALUE **ppAStack_9c;
  ASN1_VALUE *pAStack_98;
  int iStack_94;
  uint uStack_90;
  uchar **ppuStack_8c;
  undefined4 uStack_88;
  ASN1_VALUE *pAStack_84;
  uchar *puStack_80;
  int iStack_7c;
  uchar **ppuStack_78;
  undefined *puStack_74;
  int iStack_70;
  ASN1_ITEM *pAStack_6c;
  ASN1_VALUE **ppAStack_68;
  uchar *puStack_64;
  uint in_stack_ffffffc0;
  ASN1_VALUE *local_2c;
  uchar *local_28;
  ASN1_VALUE **local_24;
  
  aclass = (uchar **)PTR___stack_chk_guard_006aabf0;
  local_24 = *(ASN1_VALUE ***)PTR___stack_chk_guard_006aabf0;
  pval_00 = (ASN1_VALUE **)0xffffffff;
  local_2c = val;
  if ((out == (uchar **)0x0) || (unaff_s4 = &local_2c, *out != (uchar *)0x0)) {
    in_stack_ffffffc0 = 0;
    out_00 = (char *)out;
    it_00 = it;
    iVar2 = ASN1_item_ex_i2d(&local_2c,out,it,-1,0);
  }
  else {
    it_00 = (ASN1_ITEM *)0x0;
    out_00 = &it->itype;
    unaff_s2 = ASN1_item_ex_i2d_constprop_0(unaff_s4);
    iVar2 = unaff_s2;
    if (0 < unaff_s2) {
      it_00 = (ASN1_ITEM *)0x71;
      out_00 = "tasn_enc.c";
      unaff_s5 = (uchar *)(*(code *)PTR_CRYPTO_malloc_006a8108)(unaff_s2);
      if (unaff_s5 == (uchar *)0x0) {
        iVar2 = -1;
      }
      else {
        pval_00 = (ASN1_VALUE **)0xffffffff;
        in_stack_ffffffc0 = 0;
        out_00 = (char *)&local_28;
        it_00 = it;
        local_28 = unaff_s5;
        ASN1_item_ex_i2d(unaff_s4,(uchar **)out_00,it,-1,0);
        *out = unaff_s5;
      }
    }
  }
  if (local_24 == (ASN1_VALUE **)*aclass) {
    return iVar2;
  }
  pval = local_24;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar1 = PTR___stack_chk_guard_006aabf0;
  uStack_90 = *(uint *)it_00;
  puStack_74 = (undefined *)aclass;
  iStack_7c = *(int *)PTR___stack_chk_guard_006aabf0;
  ppuStack_78 = out;
  iStack_70 = unaff_s2;
  pAStack_6c = it;
  ppAStack_68 = unaff_s4;
  puStack_64 = unaff_s5;
  if ((uStack_90 & 0x18) == 0) {
    ppuStack_a0 = (uchar **)(in_stack_ffffffc0 & 0xc0);
    if (pval_00 == (ASN1_VALUE **)0xffffffff) {
      ppuStack_a0 = (uchar **)0x0;
    }
  }
  else {
    if (pval_00 != (ASN1_VALUE **)0xffffffff) {
      pAStack_98 = (ASN1_VALUE *)0xffffffff;
      goto LAB_005618c8;
    }
    pval_00 = (ASN1_VALUE **)it_00->utype;
    ppuStack_a0 = (uchar **)(uStack_90 & 0xc0);
  }
  if ((uStack_90 & 0x800) == 0) {
    iStack_a4 = 1;
  }
  else {
    iStack_a4 = 2;
    if ((in_stack_ffffffc0 & 0x800) == 0) {
      iStack_a4 = 1;
    }
  }
  if ((uStack_90 & 6) == 0) {
    aclass = (uchar **)(in_stack_ffffffc0 & 0xffffff3f);
    if ((uStack_90 & 0x10) != 0) {
      iVar2 = ASN1_item_ex_i2d_constprop_0(pval,it_00->funcs,aclass);
      pAStack_98 = (ASN1_VALUE *)(uStack_90 & 6);
      if (iVar2 == 0) goto LAB_005618c8;
      pAStack_98 = (ASN1_VALUE *)ASN1_object_size(iStack_a4,iVar2,(int)pval_00);
      if ((ASN1_ITEM *)out_00 == (ASN1_ITEM *)0x0) goto LAB_005618c8;
      ASN1_put_object((uchar **)out_00,iStack_a4,iVar2,(int)pval_00,(int)ppuStack_a0);
      ASN1_item_ex_i2d(pval,(uchar **)out_00,(ASN1_ITEM *)it_00->funcs,-1,(int)aclass);
      if (iStack_a4 != 2) goto LAB_005618c8;
      ASN1_put_eoc((uchar **)out_00);
      goto LAB_005618c8;
    }
    aclass = (uchar **)((uint)ppuStack_a0 | (uint)aclass);
    pAStack_98 = (ASN1_VALUE *)
                 ASN1_item_ex_i2d(pval,(uchar **)out_00,(ASN1_ITEM *)it_00->funcs,(int)pval_00,
                                  (int)aclass);
    goto LAB_005618c8;
  }
  aclass = (uchar **)(in_stack_ffffffc0 & 0xffffff3f);
  pAStack_98 = *pval;
  if (pAStack_98 == (ASN1_VALUE *)0x0) {
    pAStack_98 = (ASN1_VALUE *)0x0;
    goto LAB_005618c8;
  }
  ppuStack_8c = ppuStack_a0;
  pAVar7 = pAStack_98;
  if ((uStack_90 & 2) == 0) {
    if (pval_00 == (ASN1_VALUE **)0xffffffff) goto LAB_00561de4;
    uStack_90 = uStack_90 & 0x10;
    iStack_94 = 0;
    if (uStack_90 != 0) {
      ppuStack_8c = (uchar **)0x0;
    }
    ppAStack_9c = (ASN1_VALUE **)&SUB_00000010;
    if (uStack_90 == 0) {
      ppAStack_9c = pval_00;
    }
  }
  else {
    iStack_94 = 1;
    if ((uStack_90 & 4) != 0) {
      iStack_94 = 2;
    }
    if (pval_00 == (ASN1_VALUE **)0xffffffff) {
      uStack_90 = uStack_90 & 0x10;
      ppuStack_8c = (uchar **)0x0;
      ppAStack_9c = (ASN1_VALUE **)&DAT_00000011;
    }
    else {
      uStack_90 = uStack_90 & 0x10;
      if (uStack_90 != 0) {
        ppuStack_8c = (uchar **)0x0;
      }
      ppAStack_9c = (ASN1_VALUE **)&DAT_00000011;
      if (uStack_90 == 0) {
        ppAStack_9c = pval_00;
      }
    }
  }
  do {
    iVar2 = 0;
    for (iVar9 = 0; iVar3 = (*(code *)PTR_sk_num_006a7f2c)(pAVar7), iVar9 < iVar3; iVar9 = iVar9 + 1
        ) {
      uStack_88 = (*(code *)PTR_sk_value_006a7f24)(pAVar7,iVar9);
      iVar3 = ASN1_item_ex_i2d_constprop_0(&uStack_88,it_00->funcs,aclass);
      iVar2 = iVar2 + iVar3;
    }
    length = (ASN1_VALUE *)ASN1_object_size(iStack_a4,iVar2,(int)ppAStack_9c);
    if (uStack_90 == 0) {
      pAStack_98 = length;
      if ((ASN1_ITEM *)out_00 != (ASN1_ITEM *)0x0) {
LAB_005619e4:
        ASN1_put_object((uchar **)out_00,iStack_a4,iVar2,(int)ppAStack_9c,(int)ppuStack_8c);
        it_00 = (ASN1_ITEM *)it_00->funcs;
        puStack_80 = (uchar *)0x0;
        if ((iStack_94 == 0) || (iVar9 = (*(code *)PTR_sk_num_006a7f2c)(pAVar7), iVar9 < 2)) {
          pval_00 = &pAStack_84;
          for (iVar2 = 0; iVar9 = (*(code *)PTR_sk_num_006a7f2c)(pAVar7), iVar2 < iVar9;
              iVar2 = iVar2 + 1) {
            pAStack_84 = (ASN1_VALUE *)(*(code *)PTR_sk_value_006a7f24)(pAVar7,iVar2);
            ASN1_item_ex_i2d(pval_00,(uchar **)out_00,it_00,-1,(int)aclass);
          }
        }
        else {
          pval_00 = (ASN1_VALUE **)0x670000;
          iVar9 = (*(code *)PTR_sk_num_006a7f2c)(pAVar7);
          ppuStack_a0 = (uchar **)
                        (*(code *)PTR_CRYPTO_malloc_006a8108)(iVar9 * 0xc,"tasn_enc.c",0x1c7);
          puVar4 = (uchar *)(*(code *)PTR_CRYPTO_malloc_006a8108)(iVar2,"tasn_enc.c",0x1c8);
          if ((ppuStack_a0 != (uchar **)0x0) && (puVar4 != (uchar *)0x0)) {
            ppuVar8 = ppuStack_a0;
            puStack_80 = puVar4;
            for (pval_00 = (ASN1_VALUE **)0x0; iVar2 = (*(code *)PTR_sk_num_006a7f2c)(pAVar7),
                (int)pval_00 < iVar2; pval_00 = (ASN1_VALUE **)((int)pval_00 + 1)) {
              pAStack_84 = (ASN1_VALUE *)(*(code *)PTR_sk_value_006a7f24)(pAVar7,pval_00);
              *ppuVar8 = puStack_80;
              puVar5 = (uchar *)ASN1_item_ex_i2d(&pAStack_84,&puStack_80,it_00,-1,(int)aclass);
              ppuVar8[1] = puVar5;
              ppuVar8[2] = (uchar *)pAStack_84;
              ppuVar8 = ppuVar8 + 3;
            }
            uVar6 = (*(code *)PTR_sk_num_006a7f2c)(pAVar7);
            (*(code *)PTR_qsort_006aaa94)(ppuStack_a0,uVar6,0xc,der_cmp);
            puStack_80 = *(uchar **)out_00;
            ppuVar8 = ppuStack_a0;
            for (aclass = (uchar **)0x0; iVar2 = (*(code *)PTR_sk_num_006a7f2c)(pAVar7),
                (int)aclass < iVar2; aclass = (uchar **)((int)aclass + 1)) {
              (*(code *)PTR_memcpy_006aabf4)(puStack_80,*ppuVar8,ppuVar8[1]);
              puStack_80 = puStack_80 + (int)ppuVar8[1];
              ppuVar8 = ppuVar8 + 3;
            }
            *(uchar **)out_00 = puStack_80;
            if (iStack_94 == 2) {
              aclass = ppuStack_a0;
              for (iVar2 = 0; iVar9 = (*(code *)PTR_sk_num_006a7f2c)(pAVar7), iVar2 < iVar9;
                  iVar2 = iVar2 + 1) {
                ppuVar8 = aclass + 2;
                aclass = aclass + 3;
                (*(code *)PTR_sk_set_006a9478)(pAVar7,iVar2,*ppuVar8);
              }
            }
            (*(code *)PTR_CRYPTO_free_006a7f88)(ppuStack_a0);
            (*(code *)PTR_CRYPTO_free_006a7f88)(puVar4);
          }
        }
        if ((iStack_a4 == 2) && (ASN1_put_eoc((uchar **)out_00), uStack_90 != 0)) {
          ASN1_put_eoc((uchar **)out_00);
        }
      }
    }
    else {
      pAStack_98 = (ASN1_VALUE *)ASN1_object_size(iStack_a4,(int)length,(int)pval_00);
      if ((ASN1_ITEM *)out_00 != (ASN1_ITEM *)0x0) {
        ASN1_put_object((uchar **)out_00,iStack_a4,(int)length,(int)pval_00,(int)ppuStack_a0);
        goto LAB_005619e4;
      }
    }
LAB_005618c8:
    if (iStack_7c == *(int *)puVar1) {
      return (int)pAStack_98;
    }
    (*(code *)PTR___stack_chk_fail_006aabb8)();
    uStack_90 = extraout_v1;
LAB_00561de4:
    uStack_90 = uStack_90 & 0x10;
    iStack_94 = 0;
    ppuStack_8c = (uchar **)0x0;
    ppAStack_9c = (ASN1_VALUE **)&SUB_00000010;
    pAVar7 = pAStack_98;
  } while( true );
}

