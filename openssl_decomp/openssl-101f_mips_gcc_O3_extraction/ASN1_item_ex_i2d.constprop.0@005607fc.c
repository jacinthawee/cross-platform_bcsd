
ASN1_VALUE *
ASN1_item_ex_i2d_constprop_0(ASN1_VALUE **param_1,ASN1_ITEM *param_2,ASN1_VALUE *param_3)

{
  undefined *puVar1;
  uint uVar2;
  ASN1_VALUE *constructed;
  ASN1_VALUE **ppAVar3;
  int iVar4;
  ASN1_VALUE *pAVar5;
  void *pvVar6;
  uint uVar7;
  code *pcVar8;
  int iVar9;
  ASN1_TEMPLATE *unaff_s2;
  uint unaff_s4;
  ASN1_TEMPLATE *pAVar10;
  int iVar11;
  ASN1_TEMPLATE *local_58;
  int local_54;
  int local_50;
  int local_4c;
  int local_48;
  ASN1_VALUE *local_44;
  int local_40;
  int local_3c;
  ASN1_VALUE *local_34;
  ASN1_VALUE *local_30;
  int local_2c;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  uVar2 = (uint)param_2->itype;
  pvVar6 = param_2->funcs;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  if (uVar2 != 0) {
    pAVar5 = *param_1;
    if (pAVar5 == (ASN1_VALUE *)0x0) goto switchD_005608d8_caseD_7;
    if ((pvVar6 == (void *)0x0) || (pcVar8 = *(code **)((int)pvVar6 + 0x10), pcVar8 == (code *)0x0))
    goto LAB_005608b8;
    switch(uVar2 & 0xff) {
    default:
      goto switchD_005608d8_caseD_7;
    case 1:
      local_3c = 1;
      break;
    case 2:
      iVar9 = (*pcVar8)(6,param_1,param_2,0);
      if (iVar9 == 0) goto switchD_005608d8_caseD_7;
      iVar9 = asn1_get_choice_selector(param_1,param_2);
      if ((iVar9 < 0) || (param_2->tcount <= iVar9)) {
        (*pcVar8)(7,param_1,param_2,0);
        pAVar5 = (ASN1_VALUE *)0x0;
        goto LAB_00560908;
      }
      goto LAB_00560e18;
    case 3:
      goto switchD_0056089c_caseD_3;
    case 4:
      goto switchD_005608d8_caseD_4;
    case 5:
      goto switchD_005608d8_caseD_5;
    case 6:
      goto switchD_0056089c_caseD_6;
    }
    goto LAB_005609e0;
  }
  if ((pvVar6 == (void *)0x0) || (*(int *)((int)pvVar6 + 0x10) != 0)) {
switchD_005608d8_caseD_0:
    pAVar10 = param_2->templates;
    if (pAVar10 == (ASN1_TEMPLATE *)0x0) {
      pAVar5 = (ASN1_VALUE *)asn1_i2d_ex_primitive(param_1,0,param_2,0xffffffff,param_3);
      goto LAB_00560908;
    }
    unaff_s4 = pAVar10->flags;
    uVar2 = 0;
    if ((unaff_s4 & 0x18) == 0) {
      iVar9 = -1;
    }
    else {
      iVar9 = pAVar10->tag;
      uVar2 = unaff_s4 & 0xc0;
    }
    param_2 = (ASN1_ITEM *)((uint)param_3 & 0xffffff3f);
    if ((unaff_s4 & 0x800) == 0) {
      constructed = (ASN1_VALUE *)0x1;
    }
    else {
      constructed = (ASN1_VALUE *)&SUB_00000002;
      if (((uint)param_3 & 0x800) == 0) {
        constructed = (ASN1_VALUE *)0x1;
      }
    }
    param_3 = constructed;
    if ((unaff_s4 & 6) == 0) {
      unaff_s4 = unaff_s4 & 0x10;
      if (unaff_s4 == 0) {
        pAVar5 = (ASN1_VALUE *)
                 ASN1_item_ex_i2d(param_1,(uchar **)0x0,pAVar10->item,iVar9,(uint)param_2 | uVar2);
        goto LAB_00560908;
      }
      pAVar5 = (ASN1_VALUE *)ASN1_item_ex_i2d_constprop_0(param_1,pAVar10->item,param_2);
      if (pAVar5 != (ASN1_VALUE *)0x0) goto LAB_00560ba0;
    }
    else {
      pAVar5 = *param_1;
      if (pAVar5 != (ASN1_VALUE *)0x0) {
        if ((unaff_s4 & 2) == 0) {
          if (iVar9 == -1) {
            local_54 = 0x10;
          }
          else {
            local_54 = 0x10;
            if ((unaff_s4 & 0x10) == 0) {
              local_54 = iVar9;
            }
          }
        }
        else if (iVar9 == -1) {
          local_54 = 0x11;
        }
        else {
          local_54 = 0x11;
          if ((unaff_s4 & 0x10) == 0) {
            local_54 = iVar9;
          }
        }
        local_58 = (ASN1_TEMPLATE *)(unaff_s4 & 0x10);
        unaff_s2 = (ASN1_TEMPLATE *)0x0;
        param_1 = &local_30;
        for (unaff_s4 = 0; iVar11 = (*(code *)PTR_sk_num_006a7f2c)(pAVar5), (int)unaff_s4 < iVar11;
            unaff_s4 = unaff_s4 + 1) {
          local_30 = (ASN1_VALUE *)(*(code *)PTR_sk_value_006a7f24)(pAVar5,unaff_s4);
          iVar11 = ASN1_item_ex_i2d_constprop_0(param_1,pAVar10->item,param_2);
          unaff_s2 = (ASN1_TEMPLATE *)((int)&unaff_s2->flags + iVar11);
        }
        pAVar5 = (ASN1_VALUE *)ASN1_object_size((int)constructed,(int)unaff_s2,local_54);
        if (local_58 == (ASN1_TEMPLATE *)0x0) goto LAB_00560908;
LAB_00560ba0:
        pAVar5 = (ASN1_VALUE *)ASN1_object_size((int)constructed,(int)pAVar5,iVar9);
        goto LAB_00560908;
      }
    }
    goto switchD_005608d8_caseD_7;
  }
LAB_005608b8:
  switch(uVar2 & 0xff) {
  case 0:
    goto switchD_005608d8_caseD_0;
  case 1:
    pcVar8 = (code *)0x0;
    local_3c = 1;
    goto LAB_005609e0;
  case 2:
    iVar9 = asn1_get_choice_selector(param_1,param_2);
    if ((-1 < iVar9) && (iVar9 < param_2->tcount)) {
LAB_00560e18:
      pAVar10 = param_2->templates;
      ppAVar3 = asn1_get_field_ptr(param_1,pAVar10 + iVar9);
      pAVar5 = (ASN1_VALUE *)asn1_template_ex_i2d(ppAVar3,0,pAVar10 + iVar9,0xffffffff,param_3);
      goto LAB_00560908;
    }
    break;
  case 3:
    pAVar5 = *param_1;
switchD_0056089c_caseD_3:
    pAVar5 = (ASN1_VALUE *)(**(code **)((int)pvVar6 + 0xc))(pAVar5,0);
    goto LAB_00560908;
  case 4:
switchD_005608d8_caseD_4:
    pAVar5 = (ASN1_VALUE *)(**(code **)((int)pvVar6 + 0x14))(param_1,0,param_2,0xffffffff,param_3);
    goto LAB_00560908;
  case 5:
switchD_005608d8_caseD_5:
    local_30 = (ASN1_VALUE *)param_2->utype;
    pAVar5 = (ASN1_VALUE *)asn1_ex_i2c(param_1,(uchar *)0x0,(int *)&local_30,param_2);
    if (pAVar5 != (ASN1_VALUE *)0xffffffff) {
      if (pAVar5 == (ASN1_VALUE *)&SUB_fffffffe) {
        iVar9 = 2;
        pAVar5 = (ASN1_VALUE *)0x0;
      }
      else {
        iVar9 = 0;
      }
      if (local_30 + -0x10 < (ASN1_VALUE *)&SUB_00000002 || local_30 == (ASN1_VALUE *)0xfffffffd)
      goto LAB_00560908;
      pAVar5 = (ASN1_VALUE *)ASN1_object_size(iVar9,(int)pAVar5,(int)local_30);
      goto LAB_00560908;
    }
    break;
  case 6:
    pcVar8 = (code *)0x0;
switchD_0056089c_caseD_6:
    local_3c = 1;
    if (((uint)param_3 & 0x800) != 0) {
      local_3c = 2;
    }
LAB_005609e0:
    local_54 = asn1_enc_restore((int *)&local_34,(uchar **)0x0,param_1,param_2);
    if (-1 < local_54) {
      pAVar5 = local_34;
      if (local_54 != 0) goto LAB_00560908;
      local_34 = (ASN1_VALUE *)0x0;
      if ((pcVar8 == (code *)0x0) || (iVar9 = (*pcVar8)(6,param_1,param_2,0), iVar9 != 0)) {
        local_58 = param_2->templates;
        if (param_2->tcount < 1) goto LAB_00560d54;
        local_48 = 2;
        if (((uint)param_3 & 0x800) == 0) {
          local_48 = 1;
        }
        unaff_s4 = (uint)param_3 & 0xffffff3f;
        goto LAB_00560c10;
      }
    }
  }
switchD_005608d8_caseD_7:
  pAVar5 = (ASN1_VALUE *)0x0;
LAB_00560908:
  if (local_2c == *(int *)puVar1) {
    return pAVar5;
  }
  local_44 = (ASN1_VALUE *)(*(code *)PTR___stack_chk_fail_006aabb8)();
LAB_00560f4c:
  local_40 = 0x10;
LAB_00560ca4:
  iVar9 = 0;
  for (iVar11 = 0; iVar4 = (*(code *)PTR_sk_num_006a7f2c)(param_3), iVar11 < iVar4;
      iVar11 = iVar11 + 1) {
    local_30 = (ASN1_VALUE *)(*(code *)PTR_sk_value_006a7f24)(param_3,iVar11);
    iVar4 = ASN1_item_ex_i2d_constprop_0(&local_30,unaff_s2->item,unaff_s4);
    iVar9 = iVar9 + iVar4;
  }
  param_3 = (ASN1_VALUE *)ASN1_object_size(local_4c,iVar9,local_40);
  pAVar5 = param_3;
  do {
    if (local_44 != (ASN1_VALUE *)0x0) {
      param_3 = (ASN1_VALUE *)ASN1_object_size(local_4c,(int)pAVar5,local_50);
    }
    while( true ) {
      while( true ) {
        local_54 = local_54 + 1;
        local_58 = local_58 + 1;
        local_34 = param_3 + (int)local_34;
        if (param_2->tcount <= local_54) goto LAB_00560d54;
LAB_00560c10:
        unaff_s2 = asn1_do_adb(param_1,local_58,1);
        if (unaff_s2 == (ASN1_TEMPLATE *)0x0) goto switchD_005608d8_caseD_7;
        ppAVar3 = asn1_get_field_ptr(param_1,unaff_s2);
        uVar2 = unaff_s2->flags;
        if ((uVar2 & 0x18) == 0) {
          uVar7 = 0;
          local_50 = -1;
        }
        else {
          local_50 = unaff_s2->tag;
          uVar7 = uVar2 & 0xc0;
        }
        param_3 = (ASN1_VALUE *)(uVar2 & 6);
        local_4c = 1;
        if ((uVar2 & 0x800) != 0) {
          local_4c = local_48;
        }
        if (param_3 == (ASN1_VALUE *)0x0) break;
        param_3 = *ppAVar3;
        if (param_3 != (ASN1_VALUE *)0x0) {
          if ((uVar2 & 2) == 0) {
            local_44 = (ASN1_VALUE *)(uVar2 & 0x10);
            if (local_50 == -1) goto LAB_00560f4c;
            local_40 = 0x10;
            if (local_44 == (ASN1_VALUE *)0x0) {
              local_40 = local_50;
            }
          }
          else {
            local_44 = (ASN1_VALUE *)(uVar2 & 0x10);
            if (local_50 == -1) {
              local_40 = 0x11;
            }
            else {
              local_40 = 0x11;
              if (local_44 == (ASN1_VALUE *)0x0) {
                local_40 = local_50;
              }
            }
          }
          goto LAB_00560ca4;
        }
        param_3 = (ASN1_VALUE *)0x0;
      }
      if ((uVar2 & 0x10) != 0) break;
      param_3 = (ASN1_VALUE *)
                ASN1_item_ex_i2d(ppAVar3,(uchar **)0x0,unaff_s2->item,local_50,unaff_s4 | uVar7);
    }
    pAVar5 = (ASN1_VALUE *)ASN1_item_ex_i2d_constprop_0(ppAVar3,unaff_s2->item,unaff_s4);
    local_44 = pAVar5;
  } while( true );
LAB_00560d54:
  pAVar5 = (ASN1_VALUE *)ASN1_object_size(local_3c,(int)local_34,0x10);
  goto LAB_00560908;
}

