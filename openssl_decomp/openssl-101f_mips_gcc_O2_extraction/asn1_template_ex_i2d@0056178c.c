
ASN1_VALUE *
asn1_template_ex_i2d
          (ASN1_VALUE **param_1,uchar **param_2,ASN1_ITEM *param_3,ASN1_VALUE **param_4,uint param_5
          )

{
  undefined *puVar1;
  int iVar2;
  ASN1_VALUE *length;
  uchar *puVar3;
  uchar *puVar4;
  undefined4 uVar5;
  uint extraout_v1;
  ASN1_VALUE *pAVar6;
  uchar **unaff_s1;
  int iVar7;
  uchar **ppuVar8;
  int iVar9;
  int local_54;
  uchar **local_50;
  ASN1_VALUE **local_4c;
  ASN1_VALUE *local_48;
  int local_44;
  uint local_40;
  uchar **local_3c;
  undefined4 local_38;
  ASN1_VALUE *local_34;
  uchar *local_30;
  int local_2c;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_40 = *(uint *)param_3;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  if ((local_40 & 0x18) == 0) {
    local_50 = (uchar **)(param_5 & 0xc0);
    if (param_4 == (ASN1_VALUE **)0xffffffff) {
      local_50 = (uchar **)0x0;
    }
  }
  else {
    if (param_4 != (ASN1_VALUE **)0xffffffff) {
      local_48 = (ASN1_VALUE *)0xffffffff;
      goto LAB_005618c8;
    }
    param_4 = (ASN1_VALUE **)param_3->utype;
    local_50 = (uchar **)(local_40 & 0xc0);
  }
  if ((local_40 & 0x800) == 0) {
    local_54 = 1;
  }
  else {
    local_54 = 2;
    if ((param_5 & 0x800) == 0) {
      local_54 = 1;
    }
  }
  if ((local_40 & 6) == 0) {
    unaff_s1 = (uchar **)(param_5 & 0xffffff3f);
    if ((local_40 & 0x10) != 0) {
      iVar7 = ASN1_item_ex_i2d_constprop_0(param_1,param_3->funcs,unaff_s1);
      local_48 = (ASN1_VALUE *)(local_40 & 6);
      if (iVar7 == 0) goto LAB_005618c8;
      local_48 = (ASN1_VALUE *)ASN1_object_size(local_54,iVar7,(int)param_4);
      if (param_2 == (uchar **)0x0) goto LAB_005618c8;
      ASN1_put_object(param_2,local_54,iVar7,(int)param_4,(int)local_50);
      ASN1_item_ex_i2d(param_1,param_2,(ASN1_ITEM *)param_3->funcs,-1,(int)unaff_s1);
      if (local_54 != 2) goto LAB_005618c8;
      ASN1_put_eoc(param_2);
      goto LAB_005618c8;
    }
    unaff_s1 = (uchar **)((uint)local_50 | (uint)unaff_s1);
    local_48 = (ASN1_VALUE *)
               ASN1_item_ex_i2d(param_1,param_2,(ASN1_ITEM *)param_3->funcs,(int)param_4,
                                (int)unaff_s1);
    goto LAB_005618c8;
  }
  unaff_s1 = (uchar **)(param_5 & 0xffffff3f);
  local_48 = *param_1;
  if (local_48 == (ASN1_VALUE *)0x0) {
    local_48 = (ASN1_VALUE *)0x0;
    goto LAB_005618c8;
  }
  local_3c = local_50;
  pAVar6 = local_48;
  if ((local_40 & 2) == 0) {
    if (param_4 == (ASN1_VALUE **)0xffffffff) goto LAB_00561de4;
    local_40 = local_40 & 0x10;
    local_44 = 0;
    if (local_40 != 0) {
      local_3c = (uchar **)0x0;
    }
    local_4c = (ASN1_VALUE **)&SUB_00000010;
    if (local_40 == 0) {
      local_4c = param_4;
    }
  }
  else {
    local_44 = 1;
    if ((local_40 & 4) != 0) {
      local_44 = 2;
    }
    if (param_4 == (ASN1_VALUE **)0xffffffff) {
      local_40 = local_40 & 0x10;
      local_3c = (uchar **)0x0;
      local_4c = (ASN1_VALUE **)&DAT_00000011;
    }
    else {
      local_40 = local_40 & 0x10;
      if (local_40 != 0) {
        local_3c = (uchar **)0x0;
      }
      local_4c = (ASN1_VALUE **)&DAT_00000011;
      if (local_40 == 0) {
        local_4c = param_4;
      }
    }
  }
  do {
    iVar7 = 0;
    for (iVar9 = 0; iVar2 = (*(code *)PTR_sk_num_006a7f2c)(pAVar6), iVar9 < iVar2; iVar9 = iVar9 + 1
        ) {
      local_38 = (*(code *)PTR_sk_value_006a7f24)(pAVar6,iVar9);
      iVar2 = ASN1_item_ex_i2d_constprop_0(&local_38,param_3->funcs,unaff_s1);
      iVar7 = iVar7 + iVar2;
    }
    length = (ASN1_VALUE *)ASN1_object_size(local_54,iVar7,(int)local_4c);
    if (local_40 == 0) {
      local_48 = length;
      if (param_2 != (uchar **)0x0) {
LAB_005619e4:
        ASN1_put_object(param_2,local_54,iVar7,(int)local_4c,(int)local_3c);
        param_3 = (ASN1_ITEM *)param_3->funcs;
        local_30 = (uchar *)0x0;
        if ((local_44 == 0) || (iVar9 = (*(code *)PTR_sk_num_006a7f2c)(pAVar6), iVar9 < 2)) {
          param_4 = &local_34;
          for (iVar7 = 0; iVar9 = (*(code *)PTR_sk_num_006a7f2c)(pAVar6), iVar7 < iVar9;
              iVar7 = iVar7 + 1) {
            local_34 = (ASN1_VALUE *)(*(code *)PTR_sk_value_006a7f24)(pAVar6,iVar7);
            ASN1_item_ex_i2d(param_4,param_2,param_3,-1,(int)unaff_s1);
          }
        }
        else {
          param_4 = (ASN1_VALUE **)0x670000;
          iVar9 = (*(code *)PTR_sk_num_006a7f2c)(pAVar6);
          local_50 = (uchar **)(*(code *)PTR_CRYPTO_malloc_006a8108)(iVar9 * 0xc,"tasn_enc.c",0x1c7)
          ;
          puVar3 = (uchar *)(*(code *)PTR_CRYPTO_malloc_006a8108)(iVar7,"tasn_enc.c",0x1c8);
          if ((local_50 != (uchar **)0x0) && (puVar3 != (uchar *)0x0)) {
            ppuVar8 = local_50;
            local_30 = puVar3;
            for (param_4 = (ASN1_VALUE **)0x0; iVar7 = (*(code *)PTR_sk_num_006a7f2c)(pAVar6),
                (int)param_4 < iVar7; param_4 = (ASN1_VALUE **)((int)param_4 + 1)) {
              local_34 = (ASN1_VALUE *)(*(code *)PTR_sk_value_006a7f24)(pAVar6,param_4);
              *ppuVar8 = local_30;
              puVar4 = (uchar *)ASN1_item_ex_i2d(&local_34,&local_30,param_3,-1,(int)unaff_s1);
              ppuVar8[1] = puVar4;
              ppuVar8[2] = (uchar *)local_34;
              ppuVar8 = ppuVar8 + 3;
            }
            uVar5 = (*(code *)PTR_sk_num_006a7f2c)(pAVar6);
            (*(code *)PTR_qsort_006aaa94)(local_50,uVar5,0xc,der_cmp);
            local_30 = *param_2;
            ppuVar8 = local_50;
            for (unaff_s1 = (uchar **)0x0; iVar7 = (*(code *)PTR_sk_num_006a7f2c)(pAVar6),
                (int)unaff_s1 < iVar7; unaff_s1 = (uchar **)((int)unaff_s1 + 1)) {
              (*(code *)PTR_memcpy_006aabf4)(local_30,*ppuVar8,ppuVar8[1]);
              local_30 = local_30 + (int)ppuVar8[1];
              ppuVar8 = ppuVar8 + 3;
            }
            *param_2 = local_30;
            if (local_44 == 2) {
              unaff_s1 = local_50;
              for (iVar7 = 0; iVar9 = (*(code *)PTR_sk_num_006a7f2c)(pAVar6), iVar7 < iVar9;
                  iVar7 = iVar7 + 1) {
                ppuVar8 = unaff_s1 + 2;
                unaff_s1 = unaff_s1 + 3;
                (*(code *)PTR_sk_set_006a9478)(pAVar6,iVar7,*ppuVar8);
              }
            }
            (*(code *)PTR_CRYPTO_free_006a7f88)(local_50);
            (*(code *)PTR_CRYPTO_free_006a7f88)(puVar3);
          }
        }
        if ((local_54 == 2) && (ASN1_put_eoc(param_2), local_40 != 0)) {
          ASN1_put_eoc(param_2);
        }
      }
    }
    else {
      local_48 = (ASN1_VALUE *)ASN1_object_size(local_54,(int)length,(int)param_4);
      if (param_2 != (uchar **)0x0) {
        ASN1_put_object(param_2,local_54,(int)length,(int)param_4,(int)local_50);
        goto LAB_005619e4;
      }
    }
LAB_005618c8:
    if (local_2c == *(int *)puVar1) {
      return local_48;
    }
    (*(code *)PTR___stack_chk_fail_006aabb8)();
    local_40 = extraout_v1;
LAB_00561de4:
    local_40 = local_40 & 0x10;
    local_44 = 0;
    local_3c = (uchar **)0x0;
    local_4c = (ASN1_VALUE **)&SUB_00000010;
    pAVar6 = local_48;
  } while( true );
}

