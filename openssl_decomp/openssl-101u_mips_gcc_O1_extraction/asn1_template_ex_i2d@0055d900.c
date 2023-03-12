
ASN1_VALUE **
asn1_template_ex_i2d
          (ASN1_VALUE **param_1,ASN1_VALUE **param_2,ASN1_ITEM *param_3,ASN1_VALUE **param_4,
          uint param_5)

{
  bool bVar1;
  undefined *puVar2;
  ASN1_VALUE **pval;
  int iVar3;
  ASN1_VALUE **ppAVar4;
  uint uVar5;
  ASN1_VALUE *pAVar6;
  ASN1_VALUE *pAVar7;
  undefined4 uVar8;
  ASN1_VALUE **ppAVar9;
  int iVar10;
  int iVar11;
  ASN1_VALUE **unaff_s2;
  ASN1_VALUE **unaff_s3;
  ASN1_VALUE **ppAVar12;
  ASN1_VALUE **local_50;
  ASN1_VALUE **local_4c;
  ASN1_VALUE **local_48;
  int local_44;
  ASN1_VALUE **local_40;
  ASN1_VALUE *local_38;
  ASN1_VALUE *local_34;
  ASN1_VALUE *local_30;
  int local_2c;
  
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  ppAVar12 = *(ASN1_VALUE ***)param_3;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  if (((uint)ppAVar12 & 0x18) == 0) {
    local_50 = (ASN1_VALUE **)(param_5 & 0xc0);
    if (param_4 == (ASN1_VALUE **)0xffffffff) {
      local_50 = (ASN1_VALUE **)0x0;
    }
  }
  else {
    pval = ppAVar12;
    if (param_4 != (ASN1_VALUE **)0xffffffff) goto LAB_0055dabc;
    param_4 = (ASN1_VALUE **)param_3->utype;
    local_50 = (ASN1_VALUE **)((uint)ppAVar12 & 0xc0);
  }
  if (((uint)ppAVar12 & 0x800) == 0) {
    local_4c = (ASN1_VALUE **)0x1;
    pval = local_4c;
  }
  else {
    pval = (ASN1_VALUE **)&SUB_00000002;
    if ((param_5 & 0x800) == 0) {
      pval = (ASN1_VALUE **)0x1;
    }
  }
  local_4c = pval;
  if (((uint)ppAVar12 & 6) == 0) {
    unaff_s3 = (ASN1_VALUE **)(param_5 & 0xffffff3f);
    ppAVar9 = (ASN1_VALUE **)((uint)ppAVar12 & 6);
    ppAVar12 = (ASN1_VALUE **)((uint)ppAVar12 & 0x10);
    if (ppAVar12 != (ASN1_VALUE **)0x0) {
      unaff_s2 = (ASN1_VALUE **)
                 ASN1_item_ex_i2d(param_1,(uchar **)0x0,(ASN1_ITEM *)param_3->funcs,-1,(int)unaff_s3
                                 );
      if (unaff_s2 == (ASN1_VALUE **)0x0) goto LAB_0055dac4;
      ppAVar9 = (ASN1_VALUE **)ASN1_object_size((int)pval,(int)unaff_s2,(int)param_4);
      ppAVar12 = pval;
      if (param_2 == (ASN1_VALUE **)0x0) goto LAB_0055dac4;
      if (ppAVar9 == (ASN1_VALUE **)0xffffffff) goto LAB_0055dabc;
      ASN1_put_object((uchar **)param_2,(int)pval,(int)unaff_s2,(int)param_4,(int)local_50);
      ASN1_item_ex_i2d(param_1,(uchar **)param_2,(ASN1_ITEM *)param_3->funcs,-1,(int)unaff_s3);
      unaff_s2 = param_2;
      if (pval != (ASN1_VALUE **)&SUB_00000002) goto LAB_0055dac4;
      goto LAB_0055dcc0;
    }
    unaff_s3 = (ASN1_VALUE **)((uint)local_50 | (uint)unaff_s3);
    ppAVar9 = (ASN1_VALUE **)
              ASN1_item_ex_i2d(param_1,(uchar **)param_2,(ASN1_ITEM *)param_3->funcs,(int)param_4,
                               (int)unaff_s3);
    goto LAB_0055dac4;
  }
  unaff_s3 = (ASN1_VALUE **)(param_5 & 0xffffff3f);
  unaff_s2 = (ASN1_VALUE **)*param_1;
  if (unaff_s2 == (ASN1_VALUE **)0x0) {
    ppAVar9 = (ASN1_VALUE **)0x0;
    goto LAB_0055dac4;
  }
  local_40 = local_50;
  if (((uint)ppAVar12 & 2) == 0) {
    if (param_4 == (ASN1_VALUE **)0xffffffff) goto LAB_0055df84;
    local_44 = 0;
    if (((uint)ppAVar12 & 0x10) != 0) {
      local_40 = (ASN1_VALUE **)0x0;
    }
    local_48 = (ASN1_VALUE **)&SUB_00000010;
    if (((uint)ppAVar12 & 0x10) == 0) {
      local_48 = param_4;
    }
  }
  else {
    local_44 = 1;
    if (((uint)ppAVar12 & 4) != 0) {
      local_44 = 2;
    }
    if (param_4 == (ASN1_VALUE **)0xffffffff) {
      local_40 = (ASN1_VALUE **)0x0;
      local_48 = (ASN1_VALUE **)&DAT_00000011;
    }
    else {
      if (((uint)ppAVar12 & 0x10) != 0) {
        local_40 = (ASN1_VALUE **)0x0;
      }
      local_48 = (ASN1_VALUE **)&DAT_00000011;
      if (((uint)ppAVar12 & 0x10) == 0) {
        local_48 = param_4;
      }
    }
  }
  do {
    pval = ppAVar12;
    iVar11 = 0;
    for (iVar10 = 0; iVar3 = (*(code *)PTR_sk_num_006a6e2c)(unaff_s2), iVar10 < iVar3;
        iVar10 = iVar10 + 1) {
      local_38 = (ASN1_VALUE *)(*(code *)PTR_sk_value_006a6e24)(unaff_s2,iVar10);
      iVar3 = ASN1_item_ex_i2d(&local_38,(uchar **)0x0,(ASN1_ITEM *)param_3->funcs,-1,(int)unaff_s3)
      ;
      if ((iVar3 == -1) || (bVar1 = 0x7fffffff - iVar3 < iVar11, iVar11 = iVar11 + iVar3, bVar1))
      goto LAB_0055dabc;
    }
    ppAVar4 = (ASN1_VALUE **)ASN1_object_size((int)local_4c,iVar11,(int)local_48);
    if (ppAVar4 == (ASN1_VALUE **)0xffffffff) {
LAB_0055dabc:
      ppAVar9 = (ASN1_VALUE **)0xffffffff;
      ppAVar12 = pval;
    }
    else {
      uVar5 = (uint)pval & 0x10;
      if (uVar5 == 0) {
        ppAVar9 = ppAVar4;
        ppAVar12 = pval;
        if (param_2 != (ASN1_VALUE **)0x0) {
LAB_0055dc08:
          ASN1_put_object((uchar **)param_2,(int)local_4c,iVar11,(int)local_48,(int)local_40);
          param_3 = (ASN1_ITEM *)param_3->funcs;
          local_30 = (ASN1_VALUE *)0x0;
          if ((local_44 == 0) || (iVar10 = (*(code *)PTR_sk_num_006a6e2c)(unaff_s2), iVar10 < 2)) {
            pval = &local_34;
            for (iVar10 = 0; iVar11 = (*(code *)PTR_sk_num_006a6e2c)(unaff_s2), iVar10 < iVar11;
                iVar10 = iVar10 + 1) {
              local_34 = (ASN1_VALUE *)(*(code *)PTR_sk_value_006a6e24)(unaff_s2,iVar10);
              ASN1_item_ex_i2d(pval,(uchar **)param_2,param_3,-1,(int)unaff_s3);
            }
          }
          else {
            param_4 = (ASN1_VALUE **)0x670000;
            iVar10 = (*(code *)PTR_sk_num_006a6e2c)(unaff_s2);
            local_50 = (ASN1_VALUE **)
                       (*(code *)PTR_CRYPTO_malloc_006a7008)(iVar10 * 0xc,"tasn_enc.c",0x1ba);
            if (local_50 != (ASN1_VALUE **)0x0) {
              pAVar6 = (ASN1_VALUE *)
                       (*(code *)PTR_CRYPTO_malloc_006a7008)(iVar11,"tasn_enc.c",0x1bd);
              if (pAVar6 == (ASN1_VALUE *)0x0) {
                (*(code *)PTR_CRYPTO_free_006a6e88)(local_50);
              }
              else {
                pval = &local_30;
                param_4 = &local_34;
                ppAVar12 = local_50;
                local_30 = pAVar6;
                for (iVar10 = 0; iVar11 = (*(code *)PTR_sk_num_006a6e2c)(unaff_s2), iVar10 < iVar11;
                    iVar10 = iVar10 + 1) {
                  local_34 = (ASN1_VALUE *)(*(code *)PTR_sk_value_006a6e24)(unaff_s2,iVar10);
                  *ppAVar12 = local_30;
                  pAVar7 = (ASN1_VALUE *)
                           ASN1_item_ex_i2d(param_4,(uchar **)pval,param_3,-1,(int)unaff_s3);
                  ppAVar12[1] = pAVar7;
                  ppAVar12[2] = local_34;
                  ppAVar12 = ppAVar12 + 3;
                }
                uVar8 = (*(code *)PTR_sk_num_006a6e2c)(unaff_s2);
                (*(code *)PTR_qsort_006a9988)(local_50,uVar8,0xc,der_cmp);
                local_30 = *param_2;
                unaff_s3 = local_50;
                for (iVar10 = 0; iVar11 = (*(code *)PTR_sk_num_006a6e2c)(unaff_s2), iVar10 < iVar11;
                    iVar10 = iVar10 + 1) {
                  (*(code *)PTR_memcpy_006a9aec)(local_30,*unaff_s3,unaff_s3[1]);
                  local_30 = local_30 + (int)unaff_s3[1];
                  unaff_s3 = unaff_s3 + 3;
                }
                *param_2 = local_30;
                if (local_44 == 2) {
                  ppAVar12 = local_50;
                  for (unaff_s3 = (ASN1_VALUE **)0x0;
                      iVar10 = (*(code *)PTR_sk_num_006a6e2c)(unaff_s2), (int)unaff_s3 < iVar10;
                      unaff_s3 = (ASN1_VALUE **)((int)unaff_s3 + 1)) {
                    ppAVar4 = ppAVar12 + 2;
                    ppAVar12 = ppAVar12 + 3;
                    (*(code *)PTR_sk_set_006a8358)(unaff_s2,unaff_s3,*ppAVar4);
                  }
                }
                (*(code *)PTR_CRYPTO_free_006a6e88)(local_50);
                (*(code *)PTR_CRYPTO_free_006a6e88)(pAVar6);
              }
            }
          }
          ppAVar12 = pval;
          if ((local_4c == (ASN1_VALUE **)&SUB_00000002) &&
             (ASN1_put_eoc((uchar **)param_2), uVar5 != 0)) {
LAB_0055dcc0:
            ASN1_put_eoc((uchar **)param_2);
            ppAVar12 = pval;
          }
        }
      }
      else {
        ppAVar9 = (ASN1_VALUE **)ASN1_object_size((int)local_4c,(int)ppAVar4,(int)param_4);
        ppAVar12 = ppAVar9;
        if (param_2 != (ASN1_VALUE **)0x0) {
          pval = ppAVar9;
          if (ppAVar9 == (ASN1_VALUE **)0xffffffff) goto LAB_0055dabc;
          ASN1_put_object((uchar **)param_2,(int)local_4c,(int)ppAVar4,(int)param_4,(int)local_50);
          goto LAB_0055dc08;
        }
      }
    }
LAB_0055dac4:
    if (local_2c == *(int *)puVar2) {
      return ppAVar9;
    }
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
LAB_0055df84:
    local_44 = 0;
    local_40 = (ASN1_VALUE **)0x0;
    local_48 = (ASN1_VALUE **)&SUB_00000010;
  } while( true );
}

