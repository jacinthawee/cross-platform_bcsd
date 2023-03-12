
int ASN1_item_ndef_i2d(ASN1_VALUE *val,uchar **out,ASN1_ITEM *it)

{
  bool bVar1;
  undefined *puVar2;
  ASN1_TEMPLATE **ppAVar3;
  ASN1_TEMPLATE **pval;
  int iVar4;
  ASN1_TEMPLATE **length;
  ASN1_TEMPLATE *pAVar5;
  undefined4 uVar6;
  ASN1_TEMPLATE **ppAVar7;
  ASN1_VALUE **pval_00;
  char *out_00;
  ASN1_TEMPLATE **pval_01;
  int iVar8;
  int iVar9;
  ASN1_ITEM *pAVar10;
  ASN1_TEMPLATE **unaff_s2;
  ASN1_TEMPLATE **ppAVar11;
  ASN1_ITEM *aclass;
  ASN1_VALUE **unaff_s4;
  ASN1_ITEM *pAVar12;
  undefined4 unaff_s5;
  ASN1_TEMPLATE *unaff_s6;
  ASN1_ITEM *pAStack_a0;
  ASN1_TEMPLATE **ppAStack_9c;
  ASN1_TEMPLATE **ppAStack_98;
  int iStack_94;
  ASN1_ITEM *pAStack_90;
  ASN1_VALUE *pAStack_88;
  ASN1_TEMPLATE *pAStack_84;
  ASN1_TEMPLATE *pAStack_80;
  int iStack_7c;
  uchar **ppuStack_78;
  undefined *puStack_74;
  ASN1_TEMPLATE **ppAStack_70;
  ASN1_ITEM *pAStack_6c;
  ASN1_VALUE **ppAStack_68;
  undefined4 uStack_64;
  ASN1_TEMPLATE *pAStack_60;
  uint uVar13;
  ASN1_VALUE *local_2c;
  ASN1_TEMPLATE *local_28;
  ASN1_VALUE **local_24;
  
  puStack_74 = PTR___stack_chk_guard_006a9ae8;
  local_24 = *(ASN1_VALUE ***)PTR___stack_chk_guard_006a9ae8;
  pAVar12 = it;
  local_2c = val;
  if ((out == (uchar **)0x0) || (*out != (uchar *)0x0)) {
    pval_01 = (ASN1_TEMPLATE **)0xffffffff;
    uVar13 = 0x800;
    out_00 = (char *)out;
    ppAVar3 = (ASN1_TEMPLATE **)ASN1_item_ex_i2d(&local_2c,out,it,-1,0x800);
  }
  else {
    unaff_s5 = 0x800;
    unaff_s4 = &local_2c;
    pval_01 = (ASN1_TEMPLATE **)0xffffffff;
    out_00 = (char *)0x0;
    uVar13 = 0x800;
    unaff_s2 = (ASN1_TEMPLATE **)ASN1_item_ex_i2d(unaff_s4,(uchar **)0x0,it,-1,0x800);
    ppAVar3 = unaff_s2;
    if (0 < (int)unaff_s2) {
      pAVar12 = (ASN1_ITEM *)&DAT_0000006e;
      out_00 = "tasn_enc.c";
      unaff_s6 = (ASN1_TEMPLATE *)(*(code *)PTR_CRYPTO_malloc_006a7008)(unaff_s2);
      if (unaff_s6 == (ASN1_TEMPLATE *)0x0) {
        ppAVar3 = (ASN1_TEMPLATE **)0xffffffff;
      }
      else {
        pval_01 = (ASN1_TEMPLATE **)0xffffffff;
        uVar13 = 0x800;
        out_00 = (char *)&local_28;
        pAVar12 = it;
        local_28 = unaff_s6;
        ASN1_item_ex_i2d(unaff_s4,(uchar **)out_00,it,-1,0x800);
        *out = (uchar *)unaff_s6;
      }
    }
  }
  if (local_24 == *(ASN1_VALUE ***)puStack_74) {
    return (int)ppAVar3;
  }
  pval_00 = local_24;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  ppAVar3 = *(ASN1_TEMPLATE ***)pAVar12;
  iStack_7c = *(int *)PTR___stack_chk_guard_006a9ae8;
  ppuStack_78 = out;
  ppAStack_70 = unaff_s2;
  pAStack_6c = it;
  ppAStack_68 = unaff_s4;
  uStack_64 = unaff_s5;
  pAStack_60 = unaff_s6;
  if (((uint)ppAVar3 & 0x18) == 0) {
    pAStack_a0 = (ASN1_ITEM *)(uVar13 & 0xc0);
    if (pval_01 == (ASN1_TEMPLATE **)0xffffffff) {
      pAStack_a0 = (ASN1_ITEM *)0x0;
    }
  }
  else {
    aclass = it;
    pval = ppAVar3;
    if (pval_01 != (ASN1_TEMPLATE **)0xffffffff) goto LAB_0055dabc;
    pval_01 = (ASN1_TEMPLATE **)pAVar12->utype;
    pAStack_a0 = (ASN1_ITEM *)((uint)ppAVar3 & 0xc0);
  }
  if (((uint)ppAVar3 & 0x800) == 0) {
    ppAStack_9c = (ASN1_TEMPLATE **)0x1;
    pval = ppAStack_9c;
  }
  else {
    pval = (ASN1_TEMPLATE **)&SUB_00000002;
    if ((uVar13 & 0x800) == 0) {
      pval = (ASN1_TEMPLATE **)0x1;
    }
  }
  ppAStack_9c = pval;
  if (((uint)ppAVar3 & 6) == 0) {
    aclass = (ASN1_ITEM *)(uVar13 & 0xffffff3f);
    ppAVar7 = (ASN1_TEMPLATE **)((uint)ppAVar3 & 6);
    ppAVar3 = (ASN1_TEMPLATE **)((uint)ppAVar3 & 0x10);
    if (ppAVar3 != (ASN1_TEMPLATE **)0x0) {
      unaff_s2 = (ASN1_TEMPLATE **)
                 ASN1_item_ex_i2d(pval_00,(uchar **)0x0,(ASN1_ITEM *)pAVar12->funcs,-1,(int)aclass);
      ppAVar11 = unaff_s2;
      if (unaff_s2 == (ASN1_TEMPLATE **)0x0) goto LAB_0055dac4;
      ppAVar7 = (ASN1_TEMPLATE **)ASN1_object_size((int)pval,(int)unaff_s2,(int)pval_01);
      ppAVar3 = pval;
      if ((ASN1_TEMPLATE **)out_00 == (ASN1_TEMPLATE **)0x0) goto LAB_0055dac4;
      if (ppAVar7 == (ASN1_TEMPLATE **)0xffffffff) goto LAB_0055dabc;
      ASN1_put_object((uchar **)out_00,(int)pval,(int)unaff_s2,(int)pval_01,(int)pAStack_a0);
      ASN1_item_ex_i2d(pval_00,(uchar **)out_00,(ASN1_ITEM *)pAVar12->funcs,-1,(int)aclass);
      unaff_s2 = (ASN1_TEMPLATE **)out_00;
      ppAVar11 = (ASN1_TEMPLATE **)out_00;
      if (pval != (ASN1_TEMPLATE **)&SUB_00000002) goto LAB_0055dac4;
      goto LAB_0055dcc0;
    }
    aclass = (ASN1_ITEM *)((uint)pAStack_a0 | (uint)aclass);
    ppAVar7 = (ASN1_TEMPLATE **)
              ASN1_item_ex_i2d(pval_00,(uchar **)out_00,(ASN1_ITEM *)pAVar12->funcs,(int)pval_01,
                               (int)aclass);
    ppAVar11 = unaff_s2;
    goto LAB_0055dac4;
  }
  aclass = (ASN1_ITEM *)(uVar13 & 0xffffff3f);
  ppAVar11 = (ASN1_TEMPLATE **)*pval_00;
  if (ppAVar11 == (ASN1_TEMPLATE **)0x0) {
    ppAVar7 = (ASN1_TEMPLATE **)0x0;
    goto LAB_0055dac4;
  }
  pAStack_90 = pAStack_a0;
  if (((uint)ppAVar3 & 2) == 0) {
    if (pval_01 == (ASN1_TEMPLATE **)0xffffffff) goto LAB_0055df84;
    iStack_94 = 0;
    if (((uint)ppAVar3 & 0x10) != 0) {
      pAStack_90 = (ASN1_ITEM *)0x0;
    }
    ppAStack_98 = (ASN1_TEMPLATE **)&SUB_00000010;
    if (((uint)ppAVar3 & 0x10) == 0) {
      ppAStack_98 = pval_01;
    }
  }
  else {
    iStack_94 = 1;
    if (((uint)ppAVar3 & 4) != 0) {
      iStack_94 = 2;
    }
    if (pval_01 == (ASN1_TEMPLATE **)0xffffffff) {
      pAStack_90 = (ASN1_ITEM *)0x0;
      ppAStack_98 = (ASN1_TEMPLATE **)&DAT_00000011;
    }
    else {
      if (((uint)ppAVar3 & 0x10) != 0) {
        pAStack_90 = (ASN1_ITEM *)0x0;
      }
      ppAStack_98 = (ASN1_TEMPLATE **)&DAT_00000011;
      if (((uint)ppAVar3 & 0x10) == 0) {
        ppAStack_98 = pval_01;
      }
    }
  }
  do {
    pval = ppAVar3;
    unaff_s2 = ppAVar11;
    iVar9 = 0;
    for (iVar8 = 0; iVar4 = (*(code *)PTR_sk_num_006a6e2c)(unaff_s2), iVar8 < iVar4;
        iVar8 = iVar8 + 1) {
      pAStack_88 = (ASN1_VALUE *)(*(code *)PTR_sk_value_006a6e24)(unaff_s2,iVar8);
      iVar4 = ASN1_item_ex_i2d(&pAStack_88,(uchar **)0x0,(ASN1_ITEM *)pAVar12->funcs,-1,(int)aclass)
      ;
      if ((iVar4 == -1) || (bVar1 = 0x7fffffff - iVar4 < iVar9, iVar9 = iVar9 + iVar4, bVar1))
      goto LAB_0055dabc;
    }
    length = (ASN1_TEMPLATE **)ASN1_object_size((int)ppAStack_9c,iVar9,(int)ppAStack_98);
    if (length == (ASN1_TEMPLATE **)0xffffffff) {
LAB_0055dabc:
      ppAVar7 = (ASN1_TEMPLATE **)0xffffffff;
      ppAVar11 = unaff_s2;
      ppAVar3 = pval;
    }
    else {
      uVar13 = (uint)pval & 0x10;
      ppAVar11 = unaff_s2;
      if (uVar13 == 0) {
        ppAVar7 = length;
        ppAVar3 = pval;
        if ((ASN1_TEMPLATE **)out_00 != (ASN1_TEMPLATE **)0x0) {
LAB_0055dc08:
          ASN1_put_object((uchar **)out_00,(int)ppAStack_9c,iVar9,(int)ppAStack_98,(int)pAStack_90);
          pAVar12 = (ASN1_ITEM *)pAVar12->funcs;
          pAStack_80 = (ASN1_TEMPLATE *)0x0;
          if ((iStack_94 == 0) || (iVar8 = (*(code *)PTR_sk_num_006a6e2c)(unaff_s2), iVar8 < 2)) {
            pval = &pAStack_84;
            for (iVar8 = 0; iVar9 = (*(code *)PTR_sk_num_006a6e2c)(unaff_s2), iVar8 < iVar9;
                iVar8 = iVar8 + 1) {
              pAStack_84 = (ASN1_TEMPLATE *)(*(code *)PTR_sk_value_006a6e24)(unaff_s2,iVar8);
              ASN1_item_ex_i2d((ASN1_VALUE **)pval,(uchar **)out_00,pAVar12,-1,(int)aclass);
            }
          }
          else {
            pval_01 = (ASN1_TEMPLATE **)0x670000;
            iVar8 = (*(code *)PTR_sk_num_006a6e2c)(unaff_s2);
            pAStack_a0 = (ASN1_ITEM *)
                         (*(code *)PTR_CRYPTO_malloc_006a7008)(iVar8 * 0xc,"tasn_enc.c",0x1ba);
            if (pAStack_a0 != (ASN1_ITEM *)0x0) {
              pAVar5 = (ASN1_TEMPLATE *)
                       (*(code *)PTR_CRYPTO_malloc_006a7008)(iVar9,"tasn_enc.c",0x1bd);
              if (pAVar5 == (ASN1_TEMPLATE *)0x0) {
                (*(code *)PTR_CRYPTO_free_006a6e88)(pAStack_a0);
              }
              else {
                pval = &pAStack_80;
                pval_01 = &pAStack_84;
                pAVar10 = pAStack_a0;
                pAStack_80 = pAVar5;
                for (iVar8 = 0; iVar9 = (*(code *)PTR_sk_num_006a6e2c)(unaff_s2), iVar8 < iVar9;
                    iVar8 = iVar8 + 1) {
                  pAStack_84 = (ASN1_TEMPLATE *)(*(code *)PTR_sk_value_006a6e24)(unaff_s2,iVar8);
                  *(ASN1_TEMPLATE **)pAVar10 = pAStack_80;
                  iVar9 = ASN1_item_ex_i2d((ASN1_VALUE **)pval_01,(uchar **)pval,pAVar12,-1,
                                           (int)aclass);
                  pAVar10->utype = iVar9;
                  pAVar10->templates = pAStack_84;
                  pAVar10 = (ASN1_ITEM *)&pAVar10->tcount;
                }
                uVar6 = (*(code *)PTR_sk_num_006a6e2c)(unaff_s2);
                (*(code *)PTR_qsort_006a9988)(pAStack_a0,uVar6,0xc,der_cmp);
                pAStack_80 = *(ASN1_TEMPLATE **)out_00;
                aclass = pAStack_a0;
                for (iVar8 = 0; iVar9 = (*(code *)PTR_sk_num_006a6e2c)(unaff_s2), iVar8 < iVar9;
                    iVar8 = iVar8 + 1) {
                  (*(code *)PTR_memcpy_006a9aec)(pAStack_80,*(int *)aclass,aclass->utype);
                  pAStack_80 = (ASN1_TEMPLATE *)((int)&pAStack_80->flags + aclass->utype);
                  aclass = (ASN1_ITEM *)&aclass->tcount;
                }
                *(ASN1_TEMPLATE **)out_00 = pAStack_80;
                if (iStack_94 == 2) {
                  pAVar10 = pAStack_a0;
                  for (aclass = (ASN1_ITEM *)0x0; iVar8 = (*(code *)PTR_sk_num_006a6e2c)(unaff_s2),
                      (int)aclass < iVar8; aclass = (ASN1_ITEM *)&aclass->field_0x1) {
                    ppAVar3 = &pAVar10->templates;
                    pAVar10 = (ASN1_ITEM *)&pAVar10->tcount;
                    (*(code *)PTR_sk_set_006a8358)(unaff_s2,aclass,*ppAVar3);
                  }
                }
                (*(code *)PTR_CRYPTO_free_006a6e88)(pAStack_a0);
                (*(code *)PTR_CRYPTO_free_006a6e88)(pAVar5);
              }
            }
          }
          ppAVar3 = pval;
          if ((ppAStack_9c == (ASN1_TEMPLATE **)&SUB_00000002) &&
             (ASN1_put_eoc((uchar **)out_00), uVar13 != 0)) {
LAB_0055dcc0:
            ASN1_put_eoc((uchar **)out_00);
            ppAVar11 = unaff_s2;
            ppAVar3 = pval;
          }
        }
      }
      else {
        ppAVar7 = (ASN1_TEMPLATE **)ASN1_object_size((int)ppAStack_9c,(int)length,(int)pval_01);
        ppAVar3 = ppAVar7;
        if ((ASN1_TEMPLATE **)out_00 != (ASN1_TEMPLATE **)0x0) {
          pval = ppAVar7;
          if (ppAVar7 == (ASN1_TEMPLATE **)0xffffffff) goto LAB_0055dabc;
          ASN1_put_object((uchar **)out_00,(int)ppAStack_9c,(int)length,(int)pval_01,(int)pAStack_a0
                         );
          goto LAB_0055dc08;
        }
      }
    }
LAB_0055dac4:
    if (iStack_7c == *(int *)puVar2) {
      return (int)ppAVar7;
    }
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
LAB_0055df84:
    iStack_94 = 0;
    pAStack_90 = (ASN1_ITEM *)0x0;
    ppAStack_98 = (ASN1_TEMPLATE **)&SUB_00000010;
  } while( true );
}

