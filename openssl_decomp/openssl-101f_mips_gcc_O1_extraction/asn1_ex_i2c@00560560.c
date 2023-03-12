
int asn1_ex_i2c(ASN1_VALUE **pval,uchar *cont,int *putype,ASN1_ITEM *it)

{
  undefined *puVar1;
  int *piVar2;
  uint uVar3;
  int **pval_00;
  int iVar4;
  ASN1_VALUE **ppAVar5;
  ASN1_BIT_STRING *pAVar6;
  ASN1_TEMPLATE *pval_01;
  ASN1_VALUE *pAVar7;
  void *pvVar8;
  uint uVar9;
  int *unaff_s1;
  int iVar10;
  ASN1_TEMPLATE *unaff_s2;
  ASN1_ITEM *pAVar11;
  uint unaff_s4;
  ASN1_TEMPLATE *pAVar12;
  int iVar13;
  code *pcVar14;
  ASN1_TEMPLATE *pAStack_90;
  int iStack_8c;
  int iStack_88;
  int iStack_84;
  int iStack_80;
  int *piStack_7c;
  int iStack_78;
  int iStack_74;
  ASN1_VALUE *pAStack_6c;
  ulong uStack_68;
  int iStack_64;
  undefined *puStack_60;
  int *piStack_5c;
  uchar *local_1c;
  char local_15;
  ASN1_TEMPLATE *local_14;
  
  puStack_60 = PTR___stack_chk_guard_006aabf0;
  local_14 = *(ASN1_TEMPLATE **)PTR___stack_chk_guard_006aabf0;
  local_1c = cont;
  if ((it->funcs != (void *)0x0) &&
     (pcVar14 = *(code **)((int)it->funcs + 0x18), pcVar14 != (code *)0x0)) {
    piVar2 = (int *)(*pcVar14)();
    pAVar11 = (ASN1_ITEM *)cont;
    goto LAB_005605bc;
  }
  pAVar11 = (ASN1_ITEM *)cont;
  if (it->itype != '\0') {
    piVar2 = (int *)*pval;
    if (piVar2 != (int *)0x0) {
      pAVar11 = (ASN1_ITEM *)&DAT_00000005;
      if (it->itype != '\x05') {
        iVar10 = it->utype;
        goto LAB_00560600;
      }
      iVar10 = piVar2[1];
      *putype = iVar10;
      goto LAB_00560620;
    }
    goto LAB_005607a8;
  }
  iVar10 = it->utype;
  if (iVar10 != 1) {
    piVar2 = (int *)*pval;
    if (piVar2 == (int *)0x0) goto LAB_005607a8;
LAB_00560600:
    pAVar11 = (ASN1_ITEM *)0xfffffffc;
    if (iVar10 == -4) {
      iVar10 = *piVar2;
      pval = (ASN1_VALUE **)(piVar2 + 1);
      *putype = iVar10;
      goto LAB_00560620;
    }
  }
  iVar10 = *putype;
LAB_00560620:
  if (iVar10 == 5) {
LAB_00560680:
    piVar2 = (int *)0x0;
  }
  else if (iVar10 < 6) {
    if (iVar10 == 2) {
LAB_00560720:
      if (cont == (uchar *)0x0) {
        pAVar11 = (ASN1_ITEM *)0x0;
      }
      else {
        pAVar11 = (ASN1_ITEM *)&local_1c;
      }
      piVar2 = (int *)i2c_ASN1_INTEGER((ASN1_INTEGER *)*pval,(uchar **)pAVar11);
      goto LAB_005605bc;
    }
    if (iVar10 == 3) {
      if (cont == (uchar *)0x0) {
        pAVar11 = (ASN1_ITEM *)0x0;
      }
      else {
        pAVar11 = (ASN1_ITEM *)&local_1c;
      }
      piVar2 = (int *)i2c_ASN1_BIT_STRING((ASN1_BIT_STRING *)*pval,(uchar **)pAVar11);
      goto LAB_005605bc;
    }
    if (iVar10 != 1) goto LAB_00560654;
    pAVar6 = (ASN1_BIT_STRING *)*pval;
    if (pAVar6 == (ASN1_BIT_STRING *)0xffffffff) {
LAB_005607a8:
      piVar2 = (int *)0xffffffff;
      goto LAB_005605bc;
    }
    pAVar11 = (ASN1_ITEM *)it->utype;
    if (pAVar11 != (ASN1_ITEM *)0xfffffffc) {
      if (pAVar6 == (ASN1_BIT_STRING *)0x0) {
        if (it->size == 0) goto LAB_005607a8;
      }
      else {
        piVar2 = (int *)0xffffffff;
        if (0 < it->size) goto LAB_005605bc;
      }
    }
    piVar2 = (int *)0x1;
    local_15 = (char)pAVar6;
    if (cont == (uchar *)0x0) goto LAB_005605bc;
    piVar2 = (int *)0x1;
    pAVar11 = (ASN1_ITEM *)&local_15;
LAB_00560788:
    putype = piVar2;
    (*(code *)PTR_memcpy_006aabf4)();
    unaff_s1 = piVar2;
  }
  else {
    if (iVar10 == 10) goto LAB_00560720;
    if (iVar10 < 0xb) {
      if (iVar10 != 6) goto LAB_00560654;
      pAVar11 = (ASN1_ITEM *)((ASN1_BIT_STRING *)*pval)[1].length;
      piVar2 = (int *)((ASN1_BIT_STRING *)*pval)->flags;
LAB_0056066c:
      unaff_s1 = piVar2;
      if (cont != (uchar *)0x0) {
        putype = piVar2;
        if (piVar2 == (int *)0x0) goto LAB_00560680;
        goto LAB_00560788;
      }
    }
    else {
      if ((iVar10 == 0x102) || (iVar10 == 0x10a)) goto LAB_00560720;
LAB_00560654:
      pAVar6 = (ASN1_BIT_STRING *)*pval;
      if ((it->size != 0x800) || ((pAVar6->flags & 0x10U) == 0)) {
        pAVar11 = (ASN1_ITEM *)pAVar6->data;
        piVar2 = (int *)pAVar6->length;
        goto LAB_0056066c;
      }
      if (cont == (uchar *)0x0) {
        piVar2 = (int *)&SUB_fffffffe;
      }
      else {
        pAVar6->data = cont;
        piVar2 = (int *)&SUB_fffffffe;
        pAVar6->length = 0;
      }
    }
  }
LAB_005605bc:
  if (local_14 == *(ASN1_TEMPLATE **)puStack_60) {
    return (int)piVar2;
  }
  pval_01 = local_14;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar1 = PTR___stack_chk_guard_006aabf0;
  uVar3 = (uint)pAVar11->itype;
  pvVar8 = pAVar11->funcs;
  iStack_64 = *(int *)PTR___stack_chk_guard_006aabf0;
  piStack_5c = unaff_s1;
  if (uVar3 != 0) {
    pAVar7 = (ASN1_VALUE *)pval_01->flags;
    if (pAVar7 == (ASN1_VALUE *)0x0) goto switchD_005608d8_caseD_7;
    if ((pvVar8 == (void *)0x0) ||
       (pcVar14 = *(code **)((int)pvVar8 + 0x10), pcVar14 == (code *)0x0)) goto LAB_005608b8;
    switch(uVar3 & 0xff) {
    default:
      goto switchD_005608d8_caseD_7;
    case 1:
      iStack_74 = 1;
      break;
    case 2:
      iVar10 = (*pcVar14)(6,pval_01,pAVar11,0);
      if (iVar10 == 0) goto switchD_005608d8_caseD_7;
      iVar10 = asn1_get_choice_selector((ASN1_VALUE **)pval_01,pAVar11);
      if ((iVar10 < 0) || (pAVar11->tcount <= iVar10)) {
        (*pcVar14)(7,pval_01,pAVar11,0);
        pAVar7 = (ASN1_VALUE *)0x0;
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
  if ((pvVar8 == (void *)0x0) || (*(int *)((int)pvVar8 + 0x10) != 0)) {
switchD_005608d8_caseD_0:
    pAVar12 = pAVar11->templates;
    if (pAVar12 == (ASN1_TEMPLATE *)0x0) {
      pAVar7 = (ASN1_VALUE *)asn1_i2d_ex_primitive(pval_01,0,pAVar11,0xffffffff,putype);
      goto LAB_00560908;
    }
    unaff_s4 = pAVar12->flags;
    uVar3 = 0;
    if ((unaff_s4 & 0x18) == 0) {
      iVar10 = -1;
    }
    else {
      iVar10 = pAVar12->tag;
      uVar3 = unaff_s4 & 0xc0;
    }
    pAVar11 = (ASN1_ITEM *)((uint)putype & 0xffffff3f);
    if ((unaff_s4 & 0x800) == 0) {
      piVar2 = (int *)0x1;
    }
    else {
      piVar2 = (int *)&SUB_00000002;
      if (((uint)putype & 0x800) == 0) {
        piVar2 = (int *)0x1;
      }
    }
    putype = piVar2;
    if ((unaff_s4 & 6) == 0) {
      unaff_s4 = unaff_s4 & 0x10;
      if (unaff_s4 == 0) {
        pAVar7 = (ASN1_VALUE *)
                 ASN1_item_ex_i2d((ASN1_VALUE **)pval_01,(uchar **)0x0,pAVar12->item,iVar10,
                                  (uint)pAVar11 | uVar3);
        goto LAB_00560908;
      }
      pAVar7 = (ASN1_VALUE *)ASN1_item_ex_i2d_constprop_0(pval_01,pAVar12->item,pAVar11);
      if (pAVar7 != (ASN1_VALUE *)0x0) goto LAB_00560ba0;
    }
    else {
      pAVar7 = (ASN1_VALUE *)pval_01->flags;
      if (pAVar7 != (ASN1_VALUE *)0x0) {
        if ((unaff_s4 & 2) == 0) {
          if (iVar10 == -1) {
            iStack_8c = 0x10;
          }
          else {
            iStack_8c = 0x10;
            if ((unaff_s4 & 0x10) == 0) {
              iStack_8c = iVar10;
            }
          }
        }
        else if (iVar10 == -1) {
          iStack_8c = 0x11;
        }
        else {
          iStack_8c = 0x11;
          if ((unaff_s4 & 0x10) == 0) {
            iStack_8c = iVar10;
          }
        }
        pAStack_90 = (ASN1_TEMPLATE *)(unaff_s4 & 0x10);
        unaff_s2 = (ASN1_TEMPLATE *)0x0;
        pval_01 = (ASN1_TEMPLATE *)&uStack_68;
        for (unaff_s4 = 0; iVar13 = (*(code *)PTR_sk_num_006a7f2c)(pAVar7), (int)unaff_s4 < iVar13;
            unaff_s4 = unaff_s4 + 1) {
          uStack_68 = (*(code *)PTR_sk_value_006a7f24)(pAVar7,unaff_s4);
          iVar13 = ASN1_item_ex_i2d_constprop_0(pval_01,pAVar12->item,pAVar11);
          unaff_s2 = (ASN1_TEMPLATE *)((int)&unaff_s2->flags + iVar13);
        }
        pAVar7 = (ASN1_VALUE *)ASN1_object_size((int)piVar2,(int)unaff_s2,iStack_8c);
        if (pAStack_90 == (ASN1_TEMPLATE *)0x0) goto LAB_00560908;
LAB_00560ba0:
        pAVar7 = (ASN1_VALUE *)ASN1_object_size((int)piVar2,(int)pAVar7,iVar10);
        goto LAB_00560908;
      }
    }
    goto switchD_005608d8_caseD_7;
  }
LAB_005608b8:
  switch(uVar3 & 0xff) {
  case 0:
    goto switchD_005608d8_caseD_0;
  case 1:
    pcVar14 = (code *)0x0;
    iStack_74 = 1;
    goto LAB_005609e0;
  case 2:
    iVar10 = asn1_get_choice_selector((ASN1_VALUE **)pval_01,pAVar11);
    if ((-1 < iVar10) && (iVar10 < pAVar11->tcount)) {
LAB_00560e18:
      pAVar12 = pAVar11->templates;
      ppAVar5 = asn1_get_field_ptr((ASN1_VALUE **)pval_01,pAVar12 + iVar10);
      pAVar7 = (ASN1_VALUE *)asn1_template_ex_i2d(ppAVar5,0,pAVar12 + iVar10,0xffffffff,putype);
      goto LAB_00560908;
    }
    break;
  case 3:
    pAVar7 = (ASN1_VALUE *)pval_01->flags;
switchD_0056089c_caseD_3:
    pAVar7 = (ASN1_VALUE *)(**(code **)((int)pvVar8 + 0xc))(pAVar7,0);
    goto LAB_00560908;
  case 4:
switchD_005608d8_caseD_4:
    pAVar7 = (ASN1_VALUE *)(**(code **)((int)pvVar8 + 0x14))(pval_01,0,pAVar11,0xffffffff,putype);
    goto LAB_00560908;
  case 5:
switchD_005608d8_caseD_5:
    uStack_68 = pAVar11->utype;
    pAVar7 = (ASN1_VALUE *)
             asn1_ex_i2c((ASN1_VALUE **)pval_01,(uchar *)0x0,(int *)&uStack_68,pAVar11);
    if (pAVar7 != (ASN1_VALUE *)0xffffffff) {
      if (pAVar7 == (ASN1_VALUE *)&SUB_fffffffe) {
        iVar10 = 2;
        pAVar7 = (ASN1_VALUE *)0x0;
      }
      else {
        iVar10 = 0;
      }
      if (uStack_68 - 0x10 < 2 || uStack_68 == 0xfffffffd) goto LAB_00560908;
      pAVar7 = (ASN1_VALUE *)ASN1_object_size(iVar10,(int)pAVar7,uStack_68);
      goto LAB_00560908;
    }
    break;
  case 6:
    pcVar14 = (code *)0x0;
switchD_0056089c_caseD_6:
    iStack_74 = 1;
    if (((uint)putype & 0x800) != 0) {
      iStack_74 = 2;
    }
LAB_005609e0:
    iStack_8c = asn1_enc_restore((int *)&pAStack_6c,(uchar **)0x0,(ASN1_VALUE **)pval_01,pAVar11);
    if (-1 < iStack_8c) {
      pAVar7 = pAStack_6c;
      if (iStack_8c != 0) goto LAB_00560908;
      pAStack_6c = (ASN1_VALUE *)0x0;
      if ((pcVar14 == (code *)0x0) || (iVar10 = (*pcVar14)(6,pval_01,pAVar11,0), iVar10 != 0)) {
        pAStack_90 = pAVar11->templates;
        if (pAVar11->tcount < 1) goto LAB_00560d54;
        iStack_80 = 2;
        if (((uint)putype & 0x800) == 0) {
          iStack_80 = 1;
        }
        unaff_s4 = (uint)putype & 0xffffff3f;
        goto LAB_00560c10;
      }
    }
  }
switchD_005608d8_caseD_7:
  pAVar7 = (ASN1_VALUE *)0x0;
LAB_00560908:
  if (iStack_64 == *(int *)puVar1) {
    return (int)pAVar7;
  }
  piStack_7c = (int *)(*(code *)PTR___stack_chk_fail_006aabb8)();
LAB_00560f4c:
  iStack_78 = 0x10;
LAB_00560ca4:
  iVar10 = 0;
  for (iVar13 = 0; iVar4 = (*(code *)PTR_sk_num_006a7f2c)(putype), iVar13 < iVar4;
      iVar13 = iVar13 + 1) {
    uStack_68 = (*(code *)PTR_sk_value_006a7f24)(putype,iVar13);
    iVar4 = ASN1_item_ex_i2d_constprop_0(&uStack_68,unaff_s2->item,unaff_s4);
    iVar10 = iVar10 + iVar4;
  }
  putype = (int *)ASN1_object_size(iStack_84,iVar10,iStack_78);
  piVar2 = putype;
  do {
    if (piStack_7c != (int *)0x0) {
      putype = (int *)ASN1_object_size(iStack_84,(int)piVar2,iStack_88);
    }
    while( true ) {
      while( true ) {
        iStack_8c = iStack_8c + 1;
        pAStack_90 = pAStack_90 + 1;
        pAStack_6c = (ASN1_VALUE *)((int)putype + (int)pAStack_6c);
        if (pAVar11->tcount <= iStack_8c) goto LAB_00560d54;
LAB_00560c10:
        unaff_s2 = asn1_do_adb((ASN1_VALUE **)pval_01,pAStack_90,1);
        if (unaff_s2 == (ASN1_TEMPLATE *)0x0) goto switchD_005608d8_caseD_7;
        pval_00 = (int **)asn1_get_field_ptr((ASN1_VALUE **)pval_01,unaff_s2);
        uVar3 = unaff_s2->flags;
        if ((uVar3 & 0x18) == 0) {
          uVar9 = 0;
          iStack_88 = -1;
        }
        else {
          iStack_88 = unaff_s2->tag;
          uVar9 = uVar3 & 0xc0;
        }
        putype = (int *)(uVar3 & 6);
        iStack_84 = 1;
        if ((uVar3 & 0x800) != 0) {
          iStack_84 = iStack_80;
        }
        if (putype == (int *)0x0) break;
        putype = *pval_00;
        if (putype != (int *)0x0) {
          if ((uVar3 & 2) == 0) {
            piStack_7c = (int *)(uVar3 & 0x10);
            if (iStack_88 == -1) goto LAB_00560f4c;
            iStack_78 = 0x10;
            if (piStack_7c == (int *)0x0) {
              iStack_78 = iStack_88;
            }
          }
          else {
            piStack_7c = (int *)(uVar3 & 0x10);
            if (iStack_88 == -1) {
              iStack_78 = 0x11;
            }
            else {
              iStack_78 = 0x11;
              if (piStack_7c == (int *)0x0) {
                iStack_78 = iStack_88;
              }
            }
          }
          goto LAB_00560ca4;
        }
        putype = (int *)0x0;
      }
      if ((uVar3 & 0x10) != 0) break;
      putype = (int *)ASN1_item_ex_i2d((ASN1_VALUE **)pval_00,(uchar **)0x0,unaff_s2->item,iStack_88
                                       ,unaff_s4 | uVar9);
    }
    piVar2 = (int *)ASN1_item_ex_i2d_constprop_0(pval_00,unaff_s2->item,unaff_s4);
    piStack_7c = piVar2;
  } while( true );
LAB_00560d54:
  pAVar7 = (ASN1_VALUE *)ASN1_object_size(iStack_74,(int)pAStack_6c,0x10);
  goto LAB_00560908;
}

