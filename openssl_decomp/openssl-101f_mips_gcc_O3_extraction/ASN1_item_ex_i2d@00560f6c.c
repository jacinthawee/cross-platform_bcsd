
int ASN1_item_ex_i2d(ASN1_VALUE **pval,uchar **out,ASN1_ITEM *it,int tag,int aclass)

{
  undefined *puVar1;
  uint uVar2;
  ASN1_TEMPLATE **pval_00;
  int iVar3;
  ASN1_VALUE **ppAVar4;
  ASN1_TEMPLATE *pAVar5;
  ASN1_VALUE *pAVar6;
  void *pvVar7;
  uint uVar8;
  ASN1_TEMPLATE *unaff_s0;
  int iVar9;
  ASN1_TEMPLATE *tt;
  ASN1_TEMPLATE *unaff_s2;
  uint unaff_s6;
  int iVar10;
  int local_resc;
  ASN1_TEMPLATE *local_60;
  int local_5c;
  int local_58;
  int local_54;
  code *local_50;
  uint local_4c;
  int local_48;
  int local_44;
  ASN1_TEMPLATE *local_40;
  int local_3c;
  ASN1_TEMPLATE *local_34;
  undefined4 local_30;
  int local_2c;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  uVar2 = (uint)it->itype;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  pvVar7 = it->funcs;
  local_resc = tag;
  if (uVar2 != 0) {
    pAVar6 = *pval;
    if (pAVar6 == (ASN1_VALUE *)0x0) goto switchD_0056104c_caseD_7;
    if ((pvVar7 == (void *)0x0) ||
       (local_50 = *(code **)((int)pvVar7 + 0x10), local_50 == (code *)0x0)) goto LAB_0056102c;
    switch(uVar2 & 0xff) {
    default:
      goto switchD_0056104c_caseD_7;
    case 1:
      goto switchD_00561010_caseD_1;
    case 2:
      iVar9 = (*local_50)(6,pval,it,0);
      if (iVar9 == 0) goto switchD_0056104c_caseD_7;
      iVar9 = asn1_get_choice_selector(pval,it);
      if ((iVar9 < 0) || (it->tcount <= iVar9)) {
        (*local_50)(7,pval,it,0);
        pAVar5 = (ASN1_TEMPLATE *)0x0;
        goto LAB_0056108c;
      }
      goto LAB_00561548;
    case 3:
      goto switchD_00561010_caseD_3;
    case 4:
      goto switchD_0056104c_caseD_4;
    case 5:
      goto switchD_0056104c_caseD_5;
    case 6:
      goto switchD_00561010_caseD_6;
    }
  }
  if ((pvVar7 == (void *)0x0) || (*(int *)((int)pvVar7 + 0x10) != 0)) {
switchD_0056104c_caseD_0:
    iVar9 = tag;
    if (it->templates != (ASN1_TEMPLATE *)0x0) {
      pAVar5 = (ASN1_TEMPLATE *)asn1_template_ex_i2d(pval,out,it->templates,tag,aclass);
      goto LAB_0056108c;
    }
  }
  else {
LAB_0056102c:
    switch(uVar2 & 0xff) {
    case 0:
      goto switchD_0056104c_caseD_0;
    case 1:
      local_50 = (code *)0x0;
switchD_00561010_caseD_1:
      local_3c = 1;
LAB_00561140:
      local_4c = asn1_enc_restore((int *)&local_34,out,pval,it);
      if ((int)local_4c < 0) goto switchD_0056104c_caseD_7;
      pAVar5 = local_34;
      if (local_4c == 0) {
        local_34 = (ASN1_TEMPLATE *)0x0;
        if (tag == -1) {
          local_resc = 0x10;
          aclass = aclass & 0xffffff3f;
        }
        if ((local_50 != (code *)0x0) && (iVar9 = (*local_50)(6,pval,it,0), iVar9 == 0))
        goto switchD_0056104c_caseD_7;
        local_60 = it->templates;
        if (it->tcount < 1) goto LAB_00561408;
        local_58 = 0;
        local_48 = 1;
        if ((aclass & 0x800U) != 0) {
          local_48 = 2;
        }
        unaff_s6 = aclass & 0xffffff3f;
        goto LAB_005612c4;
      }
      goto LAB_0056108c;
    case 2:
      iVar9 = asn1_get_choice_selector(pval,it);
      if (iVar9 < 0) goto switchD_0056104c_caseD_7;
      if (it->tcount <= iVar9) goto switchD_0056104c_caseD_7;
LAB_00561548:
      unaff_s0 = it->templates + iVar9;
      ppAVar4 = asn1_get_field_ptr(pval,unaff_s0);
      pAVar5 = (ASN1_TEMPLATE *)asn1_template_ex_i2d(ppAVar4,out,unaff_s0,0xffffffff,aclass);
      goto LAB_0056108c;
    case 3:
      pAVar6 = *pval;
switchD_00561010_caseD_3:
      if (out == (uchar **)0x0) {
        pAVar5 = (ASN1_TEMPLATE *)(**(code **)((int)pvVar7 + 0xc))(pAVar6,0);
      }
      else {
        unaff_s0 = (ASN1_TEMPLATE *)*out;
        pAVar5 = (ASN1_TEMPLATE *)(**(code **)((int)pvVar7 + 0xc))(pAVar6,out);
        if (tag != -1) {
          *(byte *)&unaff_s0->flags = *(byte *)&unaff_s0->flags & 0x20 | (byte)aclass | (byte)tag;
        }
      }
      goto LAB_0056108c;
    case 4:
switchD_0056104c_caseD_4:
      pAVar5 = (ASN1_TEMPLATE *)(**(code **)((int)pvVar7 + 0x14))(pval,out,it,tag,aclass);
      goto LAB_0056108c;
    case 5:
switchD_0056104c_caseD_5:
      iVar9 = -1;
      break;
    case 6:
      local_50 = (code *)0x0;
switchD_00561010_caseD_6:
      local_3c = 1;
      if ((aclass & 0x800U) != 0) {
        local_3c = 2;
      }
      goto LAB_00561140;
    default:
      goto switchD_0056104c_caseD_7;
    }
  }
  pAVar5 = (ASN1_TEMPLATE *)asn1_i2d_ex_primitive(pval,out,it,iVar9,aclass);
LAB_0056108c:
  if (local_2c == *(int *)puVar1) {
    return (int)pAVar5;
  }
  local_40 = (ASN1_TEMPLATE *)(*(code *)PTR___stack_chk_fail_006aabb8)();
LAB_0056165c:
  local_44 = 0x10;
LAB_00561358:
  iVar9 = 0;
  for (iVar10 = 0; iVar3 = (*(code *)PTR_sk_num_006a7f2c)(unaff_s0), iVar10 < iVar3;
      iVar10 = iVar10 + 1) {
    local_30 = (*(code *)PTR_sk_value_006a7f24)(unaff_s0,iVar10);
    iVar3 = ASN1_item_ex_i2d_constprop_0(&local_30,unaff_s2->item,unaff_s6);
    iVar9 = iVar9 + iVar3;
  }
  unaff_s0 = (ASN1_TEMPLATE *)ASN1_object_size(local_54,iVar9,local_44);
  pAVar5 = unaff_s0;
  do {
    if (local_40 != (ASN1_TEMPLATE *)0x0) {
      unaff_s0 = (ASN1_TEMPLATE *)ASN1_object_size(local_54,(int)pAVar5,local_5c);
    }
    while( true ) {
      while( true ) {
        local_58 = local_58 + 1;
        local_60 = local_60 + 1;
        local_34 = (ASN1_TEMPLATE *)((int)&local_34->flags + (int)&unaff_s0->flags);
        if (it->tcount <= local_58) goto LAB_00561408;
LAB_005612c4:
        unaff_s2 = asn1_do_adb(pval,local_60,1);
        if (unaff_s2 == (ASN1_TEMPLATE *)0x0) goto switchD_0056104c_caseD_7;
        pval_00 = (ASN1_TEMPLATE **)asn1_get_field_ptr(pval,unaff_s2);
        uVar2 = unaff_s2->flags;
        if ((uVar2 & 0x18) == 0) {
          uVar8 = 0;
          local_5c = -1;
        }
        else {
          local_5c = unaff_s2->tag;
          uVar8 = uVar2 & 0xc0;
        }
        unaff_s0 = (ASN1_TEMPLATE *)(uVar2 & 6);
        local_54 = 1;
        if ((uVar2 & 0x800) != 0) {
          local_54 = local_48;
        }
        if (unaff_s0 == (ASN1_TEMPLATE *)0x0) break;
        unaff_s0 = *pval_00;
        if (unaff_s0 != (ASN1_TEMPLATE *)0x0) {
          if ((uVar2 & 2) == 0) {
            local_40 = (ASN1_TEMPLATE *)(uVar2 & 0x10);
            if (local_5c == -1) goto LAB_0056165c;
            local_44 = 0x10;
            if (local_40 == (ASN1_TEMPLATE *)0x0) {
              local_44 = local_5c;
            }
          }
          else {
            local_40 = (ASN1_TEMPLATE *)(uVar2 & 0x10);
            if (local_5c == -1) {
              local_44 = 0x11;
            }
            else {
              local_44 = 0x11;
              if (local_40 == (ASN1_TEMPLATE *)0x0) {
                local_44 = local_5c;
              }
            }
          }
          goto LAB_00561358;
        }
        unaff_s0 = (ASN1_TEMPLATE *)0x0;
      }
      if ((uVar2 & 0x10) != 0) break;
      unaff_s0 = (ASN1_TEMPLATE *)
                 ASN1_item_ex_i2d((ASN1_VALUE **)pval_00,(uchar **)0x0,unaff_s2->item,local_5c,
                                  unaff_s6 | uVar8);
    }
    pAVar5 = (ASN1_TEMPLATE *)ASN1_item_ex_i2d_constprop_0(pval_00,unaff_s2->item,unaff_s6);
    local_40 = pAVar5;
  } while( true );
LAB_00561408:
  unaff_s0 = (ASN1_TEMPLATE *)ASN1_object_size(local_3c,(int)local_34,local_resc);
  pAVar5 = unaff_s0;
  if (out != (uchar **)0x0) {
    ASN1_put_object(out,local_3c,(int)local_34,local_resc,aclass);
    tt = it->templates;
    if (0 < it->tcount) {
      do {
        unaff_s2 = asn1_do_adb(pval,tt,1);
        if (unaff_s2 == (ASN1_TEMPLATE *)0x0) {
          pAVar5 = (ASN1_TEMPLATE *)0x0;
          goto LAB_0056108c;
        }
        tt = tt + 1;
        unaff_s6 = local_4c + 1;
        ppAVar4 = asn1_get_field_ptr(pval,unaff_s2);
        asn1_template_ex_i2d(ppAVar4,out,unaff_s2,0xffffffff,aclass);
        local_4c = unaff_s6;
      } while ((int)unaff_s6 < it->tcount);
    }
    if (local_3c == 2) {
      ASN1_put_eoc(out);
    }
    if ((local_50 != (code *)0x0) && (iVar9 = (*local_50)(7,pval,it,0), iVar9 == 0)) {
switchD_0056104c_caseD_7:
      pAVar5 = (ASN1_TEMPLATE *)0x0;
    }
  }
  goto LAB_0056108c;
}

