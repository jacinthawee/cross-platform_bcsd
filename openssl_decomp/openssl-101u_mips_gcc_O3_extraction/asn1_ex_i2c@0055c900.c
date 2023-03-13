
int asn1_ex_i2c(ASN1_VALUE **pval,uchar *cont,int *putype,ASN1_ITEM *it)

{
  bool bVar1;
  bool bVar2;
  undefined *puVar3;
  ASN1_ITEM *pAVar4;
  uint uVar5;
  ASN1_TEMPLATE **ppAVar6;
  int iVar7;
  ASN1_VALUE **ppAVar8;
  int *piVar9;
  ASN1_ITEM *pAVar10;
  int *piVar11;
  ASN1_BIT_STRING *pAVar12;
  ASN1_ITEM *pAVar13;
  ASN1_TEMPLATE **pp;
  void *pvVar14;
  undefined *puVar15;
  uint uVar16;
  int iVar17;
  ASN1_ITEM *unaff_s1;
  int length;
  ASN1_TEMPLATE *pAVar18;
  ASN1_TEMPLATE *unaff_s2;
  ASN1_TEMPLATE *unaff_s3;
  uint unaff_s5;
  uint unaff_s7;
  code *pcVar19;
  ASN1_TEMPLATE *pAStack_94;
  long lStack_90;
  int iStack_8c;
  int iStack_88;
  code *pcStack_84;
  int iStack_80;
  ASN1_TEMPLATE *pAStack_7c;
  int iStack_78;
  int iStack_74;
  undefined uStack_6d;
  ASN1_ITEM *pAStack_6c;
  ASN1_TEMPLATE *pAStack_68;
  int iStack_64;
  undefined *puStack_60;
  ASN1_ITEM *pAStack_5c;
  ASN1_ITEM *pAStack_2c;
  undefined *local_28;
  ASN1_TEMPLATE *local_1c;
  undefined local_15;
  int *local_14;
  
  puStack_60 = PTR___stack_chk_guard_006a9ae8;
  local_28 = &_gp;
  local_14 = *(int **)PTR___stack_chk_guard_006a9ae8;
  local_1c = (ASN1_TEMPLATE *)cont;
  if ((it->funcs == (void *)0x0) ||
     (pcVar19 = *(code **)((int)it->funcs + 0x18), pcVar19 == (code *)0x0)) {
    if (it->itype == '\0') {
      iVar17 = it->utype;
      pp = (ASN1_TEMPLATE **)cont;
      if (iVar17 != 1) {
        piVar11 = (int *)*pval;
        if (piVar11 == (int *)0x0) goto LAB_0055cb00;
LAB_0055c9a0:
        pp = (ASN1_TEMPLATE **)0xfffffffc;
        if (iVar17 == -4) {
          iVar17 = *piVar11;
          pval = (ASN1_VALUE **)(piVar11 + 1);
          *putype = iVar17;
          goto LAB_0055c9c0;
        }
      }
      iVar17 = *putype;
LAB_0055c9c0:
      switch(iVar17) {
      default:
        pAVar12 = (ASN1_BIT_STRING *)*pval;
        if ((it->size != 0x800) || ((pAVar12->flags & 0x10U) == 0)) {
          pp = (ASN1_TEMPLATE **)pAVar12->data;
          pAVar4 = (ASN1_ITEM *)pAVar12->length;
          goto LAB_0055ca18;
        }
        if (cont == (uchar *)0x0) {
          pAVar4 = (ASN1_ITEM *)&SUB_fffffffe;
        }
        else {
          pAVar12->data = cont;
          pAVar4 = (ASN1_ITEM *)&SUB_fffffffe;
          pAVar12->length = 0;
        }
        break;
      case 1:
        pAVar12 = (ASN1_BIT_STRING *)*pval;
        if (pAVar12 == (ASN1_BIT_STRING *)0xffffffff) goto LAB_0055cb00;
        pp = (ASN1_TEMPLATE **)it->utype;
        if (pp != (ASN1_TEMPLATE **)0xfffffffc) {
          if (pAVar12 == (ASN1_BIT_STRING *)0x0) {
            if (it->size == 0) goto LAB_0055cb00;
          }
          else {
            pAVar4 = (ASN1_ITEM *)0xffffffff;
            if (0 < it->size) break;
          }
        }
        pAVar4 = (ASN1_ITEM *)0x1;
        local_15 = SUB41(pAVar12,0);
        if (cont == (uchar *)0x0) break;
        pAVar4 = (ASN1_ITEM *)0x1;
        pp = (ASN1_TEMPLATE **)&local_15;
LAB_0055cac4:
        putype = (int *)pAVar4;
        (*(code *)PTR_memcpy_006a9aec)();
        unaff_s1 = pAVar4;
        break;
      case 2:
      case 10:
        if (cont == (uchar *)0x0) {
          pp = (ASN1_TEMPLATE **)0x0;
        }
        else {
          pp = &local_1c;
        }
        pAVar4 = (ASN1_ITEM *)i2c_ASN1_INTEGER((ASN1_INTEGER *)*pval,(uchar **)pp);
        break;
      case 3:
        if (cont == (uchar *)0x0) {
          pp = (ASN1_TEMPLATE **)0x0;
        }
        else {
          pp = &local_1c;
        }
        pAVar4 = (ASN1_ITEM *)i2c_ASN1_BIT_STRING((ASN1_BIT_STRING *)*pval,(uchar **)pp);
        break;
      case 5:
switchD_0055c9dc_caseD_5:
        pAVar4 = (ASN1_ITEM *)0x0;
        break;
      case 6:
        pp = (ASN1_TEMPLATE **)((ASN1_BIT_STRING *)*pval)[1].length;
        pAVar4 = (ASN1_ITEM *)((ASN1_BIT_STRING *)*pval)->flags;
LAB_0055ca18:
        unaff_s1 = pAVar4;
        if (cont != (uchar *)0x0) {
          putype = (int *)pAVar4;
          if (pAVar4 != (ASN1_ITEM *)0x0) goto LAB_0055cac4;
          goto switchD_0055c9dc_caseD_5;
        }
      }
    }
    else {
      piVar11 = (int *)*pval;
      pp = (ASN1_TEMPLATE **)&DAT_00000005;
      if (piVar11 != (int *)0x0) {
        if (it->itype != '\x05') {
          iVar17 = it->utype;
          goto LAB_0055c9a0;
        }
        iVar17 = piVar11[1];
        *putype = iVar17;
        goto LAB_0055c9c0;
      }
LAB_0055cb00:
      pAVar4 = (ASN1_ITEM *)0xffffffff;
    }
  }
  else {
    pAVar4 = (ASN1_ITEM *)(*pcVar19)();
    pp = (ASN1_TEMPLATE **)cont;
  }
  if ((int **)local_14 == *(int ***)puStack_60) {
    return (int)pAVar4;
  }
  piVar11 = local_14;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar3 = PTR___stack_chk_guard_006a9ae8;
  iStack_64 = *(int *)PTR___stack_chk_guard_006a9ae8;
  uVar5 = (uint)*(char *)putype;
  pvVar14 = *(void **)((int)putype + 0x10);
  pAStack_2c = it;
  pAStack_5c = unaff_s1;
  if (uVar5 != 0) {
    pAVar12 = (ASN1_BIT_STRING *)*piVar11;
    if (pAVar12 == (ASN1_BIT_STRING *)0x0) goto switchD_0055cc3c_caseD_7;
    if ((pvVar14 == (void *)0x0) ||
       (pcStack_84 = *(code **)((int)pvVar14 + 0x10), pcStack_84 == (code *)0x0)) goto LAB_0055cc1c;
    switch(uVar5 & 0xff) {
    default:
      goto switchD_0055cc3c_caseD_7;
    case 1:
      iStack_74 = 1;
      break;
    case 2:
      iVar17 = (*pcStack_84)(6,piVar11,putype,0);
      if (iVar17 == 0) goto switchD_0055cc3c_caseD_7;
      iVar17 = asn1_get_choice_selector((ASN1_VALUE **)piVar11,(ASN1_ITEM *)putype);
      if ((iVar17 < 0) || (*(long *)((int)putype + 0xc) <= iVar17)) {
        (*pcStack_84)(7,piVar11,putype,0);
        pAVar4 = (ASN1_ITEM *)0x0;
        goto LAB_0055cc80;
      }
      goto LAB_0055d2a4;
    case 3:
      goto switchD_0055cc00_caseD_3;
    case 4:
      goto switchD_0055cc3c_caseD_4;
    case 5:
      goto switchD_0055cc3c_caseD_5;
    case 6:
      goto switchD_0055cc00_caseD_6;
    }
    goto LAB_0055cd90;
  }
  if ((pvVar14 != (void *)0x0) && (*(int *)((int)pvVar14 + 0x10) == 0)) {
LAB_0055cc1c:
    switch(uVar5 & 0xff) {
    case 0:
      goto switchD_0055cc3c_caseD_0;
    case 1:
      pcStack_84 = (code *)0x0;
      iStack_74 = 1;
      break;
    case 2:
      iVar17 = asn1_get_choice_selector((ASN1_VALUE **)piVar11,(ASN1_ITEM *)putype);
      if (iVar17 < 0) goto switchD_0055cc3c_caseD_7;
      if (*(long *)((int)putype + 0xc) <= iVar17) goto switchD_0055cc3c_caseD_7;
LAB_0055d2a4:
      pAVar18 = *(ASN1_TEMPLATE **)((int)putype + 8);
      ppAVar8 = asn1_get_field_ptr((ASN1_VALUE **)piVar11,pAVar18 + iVar17);
      pAVar4 = (ASN1_ITEM *)asn1_template_ex_i2d(ppAVar8,pp,pAVar18 + iVar17,0xffffffff,&_gp);
      goto LAB_0055cc80;
    case 3:
      pAVar12 = (ASN1_BIT_STRING *)*piVar11;
switchD_0055cc00_caseD_3:
      if (pp == (ASN1_TEMPLATE **)0x0) {
        pAVar4 = (ASN1_ITEM *)(**(code **)((int)pvVar14 + 0xc))(pAVar12,0);
      }
      else {
        pAVar18 = *pp;
        pAVar4 = (ASN1_ITEM *)(**(code **)((int)pvVar14 + 0xc))(pAVar12,pp);
        if (it != (ASN1_ITEM *)0xffffffff) {
          *(byte *)&pAVar18->flags = *(byte *)&pAVar18->flags & 0x20 | (byte)it | 0xe0;
        }
      }
      goto LAB_0055cc80;
    case 4:
switchD_0055cc3c_caseD_4:
      pAVar4 = (ASN1_ITEM *)(**(code **)((int)pvVar14 + 0x14))(piVar11,pp,putype,it,&_gp);
      goto LAB_0055cc80;
    case 5:
switchD_0055cc3c_caseD_5:
      pAStack_68 = *(ASN1_TEMPLATE **)((int)putype + 4);
      unaff_s2 = (ASN1_TEMPLATE *)&pAStack_68;
      pAVar4 = (ASN1_ITEM *)
               asn1_ex_i2c((ASN1_VALUE **)piVar11,(uchar *)0x0,(int *)unaff_s2,(ASN1_ITEM *)putype);
      unaff_s3 = pAStack_68;
      bVar1 = &SUB_00000002 <= &pAStack_68[-1].tag;
      bVar2 = pAStack_68 != (ASN1_TEMPLATE *)0xfffffffd;
      if (pAVar4 == (ASN1_ITEM *)0xffffffff) goto switchD_0055cc3c_caseD_7;
      unaff_s5 = 2;
      if (pAVar4 == (ASN1_ITEM *)&SUB_fffffffe) {
        pAVar4 = (ASN1_ITEM *)0x0;
      }
      else {
        unaff_s5 = 0;
      }
      if (pp == (ASN1_TEMPLATE **)0x0) {
LAB_0055ce5c:
        if (!bVar1 || !bVar2) goto LAB_0055cc80;
      }
      else {
        if (bVar1 && bVar2) {
          ASN1_put_object((uchar **)pp,unaff_s5,(int)pAVar4,(int)pAStack_68,(int)&_gp);
        }
        asn1_ex_i2c((ASN1_VALUE **)piVar11,(uchar *)*pp,(int *)unaff_s2,(ASN1_ITEM *)putype);
        if (unaff_s5 == 0) {
          *pp = (ASN1_TEMPLATE *)(&pAVar4->itype + (int)&(*pp)->flags);
          goto LAB_0055ce5c;
        }
        ASN1_put_eoc((uchar **)pp);
        if (!bVar1 || !bVar2) goto LAB_0055cc80;
      }
      pAVar4 = (ASN1_ITEM *)ASN1_object_size(unaff_s5,(int)pAVar4,(int)unaff_s3);
      goto LAB_0055cc80;
    case 6:
      pcStack_84 = (code *)0x0;
switchD_0055cc00_caseD_6:
      iStack_74 = 2;
      break;
    default:
      goto switchD_0055cc3c_caseD_7;
    }
LAB_0055cd90:
    pAStack_7c = (ASN1_TEMPLATE *)
                 asn1_enc_restore((int *)&pAStack_6c,(uchar **)pp,(ASN1_VALUE **)piVar11,
                                  (ASN1_ITEM *)putype);
    if ((int)pAStack_7c < 0) goto switchD_0055cc3c_caseD_7;
    pAVar4 = pAStack_6c;
    if (pAStack_7c == (ASN1_TEMPLATE *)0x0) {
      pAStack_6c = (ASN1_ITEM *)0x0;
      if (it == (ASN1_ITEM *)0xffffffff) {
        pAStack_2c = (ASN1_ITEM *)&SUB_00000010;
        local_28 = (undefined *)0x6aed20;
      }
      if ((pcStack_84 != (code *)0x0) && (iVar17 = (*pcStack_84)(6,piVar11,putype,0), iVar17 == 0))
      goto switchD_0055cc3c_caseD_7;
      pAStack_94 = *(ASN1_TEMPLATE **)((int)putype + 8);
      if (*(long *)((int)putype + 0xc) < 1) goto LAB_0055d0d4;
      iStack_8c = 0;
      iStack_80 = 1;
      if (((uint)local_28 & 0x800) != 0) {
        iStack_80 = 2;
      }
      unaff_s7 = (uint)local_28 & 0xffffff3f;
      goto LAB_0055cf38;
    }
    goto LAB_0055cc80;
  }
switchD_0055cc3c_caseD_0:
  if (*(ASN1_TEMPLATE **)((int)putype + 8) != (ASN1_TEMPLATE *)0x0) {
    pAVar4 = (ASN1_ITEM *)
             asn1_template_ex_i2d(piVar11,pp,*(ASN1_TEMPLATE **)((int)putype + 8),it,&_gp);
    goto LAB_0055cc80;
  }
  pAVar13 = *(ASN1_ITEM **)((int)putype + 4);
  pAStack_6c = pAVar13;
  if (pvVar14 != (void *)0x0) {
    if (*(code **)((int)pvVar14 + 0x18) == (code *)0x0) goto LAB_0055d5c0;
    pAVar4 = (ASN1_ITEM *)(**(code **)((int)pvVar14 + 0x18))(piVar11,0,&pAStack_6c,putype);
    goto LAB_0055d3a8;
  }
LAB_0055d5c0:
  piVar9 = piVar11;
  if (pAVar13 == (ASN1_ITEM *)0x1) {
switchD_0055d604_caseD_1:
    pAVar4 = (ASN1_ITEM *)0xffffffff;
    if ((int *)*piVar9 == (int *)0xffffffff) {
      pAVar10 = (ASN1_ITEM *)0x1;
    }
    else {
      pAVar4 = (ASN1_ITEM *)0x1;
      if (pAVar13 == (ASN1_ITEM *)0xfffffffc) {
        pAVar10 = (ASN1_ITEM *)0x1;
      }
      else {
        pAVar4 = (ASN1_ITEM *)0x1;
        if ((int *)*piVar9 == (int *)0x0) {
          pAVar10 = (ASN1_ITEM *)0x1;
          if (*(long *)((int)putype + 0x14) == 0) {
            pAVar4 = (ASN1_ITEM *)0xffffffff;
          }
        }
        else {
          pAVar4 = (ASN1_ITEM *)0x1;
          pAVar10 = (ASN1_ITEM *)0x1;
          if (0 < *(long *)((int)putype + 0x14)) {
            pAVar4 = (ASN1_ITEM *)0xffffffff;
          }
        }
      }
    }
    goto LAB_0055d3b8;
  }
  pAVar12 = (ASN1_BIT_STRING *)*piVar11;
  pAVar10 = pAVar13;
  if (pAVar12 == (ASN1_BIT_STRING *)0x0) {
    if (&pAVar13[-1].tcount < &SUB_00000002) goto switchD_0055cc3c_caseD_7;
    pAVar4 = (ASN1_ITEM *)0xffffffff;
    goto LAB_0055d3b8;
  }
  if (pAVar13 == (ASN1_ITEM *)0xfffffffc) {
    piVar9 = &pAVar12->type;
    pAVar10 = (ASN1_ITEM *)pAVar12->length;
  }
  pAStack_6c = pAVar10;
  switch(pAVar10) {
  default:
    if ((*(long *)((int)putype + 0x14) != 0x800) || (((uint)((ASN1_ITEM **)*piVar9)[3] & 0x10) == 0)
       ) {
      pAVar4 = *(ASN1_ITEM **)*piVar9;
      goto LAB_0055d3a8;
    }
    bVar1 = false;
    if ((long *)0x1 < &pAVar10[-1].tcount) {
      pAVar4 = (ASN1_ITEM *)&SUB_fffffffe;
      break;
    }
    goto LAB_0055d6c4;
  case (ASN1_ITEM *)0x1:
    goto switchD_0055d604_caseD_1;
  case (ASN1_ITEM *)0x2:
  case (ASN1_ITEM *)0xa:
    pcVar19 = (code *)PTR_i2c_ASN1_INTEGER_006a8d8c;
    goto LAB_0055d618;
  case (ASN1_ITEM *)0x3:
    pcVar19 = (code *)PTR_i2c_ASN1_BIT_STRING_006a8d88;
LAB_0055d618:
    pAVar4 = (ASN1_ITEM *)(*pcVar19)((int *)*piVar9,0);
LAB_0055d3a8:
    bVar1 = false;
    pAVar10 = pAStack_6c;
    if ((long *)0x1 < &pAStack_6c[-1].tcount) break;
    goto LAB_0055d3c0;
  case (ASN1_ITEM *)0x5:
    pAVar4 = (ASN1_ITEM *)0x0;
    break;
  case (ASN1_ITEM *)0x6:
    pAVar4 = (ASN1_ITEM *)((int *)*piVar9)[3];
  }
LAB_0055d3b8:
  bVar1 = pAVar10 != (ASN1_ITEM *)0xfffffffd;
LAB_0055d3c0:
  if (pAVar4 == (ASN1_ITEM *)0xffffffff) goto switchD_0055cc3c_caseD_7;
  if (pAVar4 == (ASN1_ITEM *)&SUB_fffffffe) {
LAB_0055d6c4:
    unaff_s2 = (ASN1_TEMPLATE *)&SUB_00000002;
    pAVar4 = (ASN1_ITEM *)0x0;
  }
  else {
    unaff_s2 = (ASN1_TEMPLATE *)0x0;
  }
  if (it == (ASN1_ITEM *)0xffffffff) {
    pAStack_2c = pAVar10;
  }
  if (pp != (ASN1_TEMPLATE **)0x0) {
    if (bVar1) {
      ASN1_put_object((uchar **)pp,(int)unaff_s2,(int)pAVar4,(int)pAStack_2c,(int)&_gp);
    }
    pAStack_68 = *pp;
    if ((*(void **)((int)putype + 0x10) == (void *)0x0) ||
       (pcVar19 = *(code **)((int)*(void **)((int)putype + 0x10) + 0x18), pcVar19 == (code *)0x0)) {
      if (*(char *)putype == '\0') {
        iVar17 = *(long *)((int)putype + 4);
        if (iVar17 != 1) {
          pAVar12 = (ASN1_BIT_STRING *)*piVar11;
          if (pAVar12 == (ASN1_BIT_STRING *)0x0) goto switchD_0055d4b4_caseD_5;
LAB_0055d488:
          if (iVar17 == -4) {
            pAStack_6c = (ASN1_ITEM *)pAVar12->length;
            piVar11 = &pAVar12->type;
          }
        }
      }
      else {
        pAVar12 = (ASN1_BIT_STRING *)*piVar11;
        if (pAVar12 == (ASN1_BIT_STRING *)0x0) goto switchD_0055d4b4_caseD_5;
        if (*(char *)putype != '\x05') {
          iVar17 = *(long *)((int)putype + 4);
          goto LAB_0055d488;
        }
        pAStack_6c = (ASN1_ITEM *)pAVar12->type;
      }
      switch(pAStack_6c) {
      default:
        piVar9 = (int *)*piVar11;
        if ((*(long *)((int)putype + 0x14) != 0x800) || ((piVar9[3] & 0x10U) == 0)) {
          puVar15 = (undefined *)piVar9[2];
          iVar17 = *piVar9;
          goto LAB_0055d4d8;
        }
        if (pAStack_68 != (ASN1_TEMPLATE *)0x0) {
          piVar9[2] = (int)pAStack_68;
          *piVar9 = 0;
        }
        break;
      case (ASN1_ITEM *)0x1:
        piVar9 = (int *)*piVar11;
        if (piVar9 != (int *)0xffffffff) {
          if (*(long *)((int)putype + 4) != -4) {
            if (piVar9 == (int *)0x0) {
              if (*(long *)((int)putype + 0x14) != 0) goto LAB_0055d56c;
            }
            else if (*(long *)((int)putype + 0x14) < 1) goto LAB_0055d56c;
            break;
          }
LAB_0055d56c:
          uStack_6d = SUB41(piVar9,0);
          if (pAStack_68 == (ASN1_TEMPLATE *)0x0) break;
          iVar17 = 1;
          puVar15 = &uStack_6d;
          goto LAB_0055d4e8;
        }
        break;
      case (ASN1_ITEM *)0x2:
      case (ASN1_ITEM *)0xa:
        if (pAStack_68 == (ASN1_TEMPLATE *)0x0) {
          ppAVar6 = (ASN1_TEMPLATE **)0x0;
        }
        else {
          ppAVar6 = &pAStack_68;
        }
        i2c_ASN1_INTEGER((ASN1_INTEGER *)*piVar11,(uchar **)ppAVar6);
        break;
      case (ASN1_ITEM *)0x3:
        if (pAStack_68 == (ASN1_TEMPLATE *)0x0) {
          ppAVar6 = (ASN1_TEMPLATE **)0x0;
        }
        else {
          ppAVar6 = &pAStack_68;
        }
        i2c_ASN1_BIT_STRING((ASN1_BIT_STRING *)*piVar11,(uchar **)ppAVar6);
        break;
      case (ASN1_ITEM *)0x5:
        break;
      case (ASN1_ITEM *)0x6:
        puVar15 = (undefined *)((int *)*piVar11)[4];
        iVar17 = ((int *)*piVar11)[3];
LAB_0055d4d8:
        if ((pAStack_68 != (ASN1_TEMPLATE *)0x0) && (iVar17 != 0)) {
LAB_0055d4e8:
          (*(code *)PTR_memcpy_006a9aec)(pAStack_68,puVar15,iVar17);
        }
      }
    }
    else {
      (*pcVar19)(piVar11,pAStack_68,&pAStack_6c,putype);
    }
switchD_0055d4b4_caseD_5:
    if (unaff_s2 == (ASN1_TEMPLATE *)0x0) {
      *pp = (ASN1_TEMPLATE *)(&pAVar4->itype + (int)&(*pp)->flags);
    }
    else {
      ASN1_put_eoc((uchar **)pp);
    }
  }
  if (bVar1) {
    pAVar4 = (ASN1_ITEM *)ASN1_object_size((int)unaff_s2,(int)pAVar4,(int)pAStack_2c);
  }
LAB_0055cc80:
  if (iStack_64 == *(int *)puVar3) {
    return (int)pAVar4;
  }
  iStack_78 = (*(code *)PTR___stack_chk_fail_006a9ab0)();
LAB_0055cfd0:
  length = 0;
  for (iVar17 = 0; iVar7 = (*(code *)PTR_sk_num_006a6e2c)(unaff_s2), iVar17 < iVar7;
      iVar17 = iVar17 + 1) {
    pAStack_68 = (ASN1_TEMPLATE *)(*(code *)PTR_sk_value_006a6e24)(unaff_s2,iVar17);
    iVar7 = ASN1_item_ex_i2d((ASN1_VALUE **)&pAStack_68,(uchar **)0x0,unaff_s3->item,-1,unaff_s7);
    if ((iVar7 == -1) || (bVar1 = 0x7fffffff - iVar7 < length, length = length + iVar7, bVar1))
    goto LAB_0055d204;
  }
  uVar5 = ASN1_object_size(iStack_88,length,iStack_78);
  if (uVar5 == 0xffffffff) {
LAB_0055d204:
    uVar5 = 0xffffffff;
  }
  else {
    unaff_s5 = unaff_s5 & 0x10;
    if (unaff_s5 != 0) goto LAB_0055d1d8;
  }
LAB_0055d084:
  do {
    pAVar4 = (ASN1_ITEM *)0xffffffff;
    uVar16 = uVar5;
    if (uVar5 == 0xffffffff) goto LAB_0055cc80;
    do {
      if (0x7fffffff - (int)pAStack_6c < (int)uVar16) goto LAB_0055d2f0;
      pAStack_6c = (ASN1_ITEM *)(&pAStack_6c->itype + uVar16);
      iStack_8c = iStack_8c + 1;
      pAStack_94 = pAStack_94 + 1;
      if (*(long *)((int)putype + 0xc) <= iStack_8c) goto LAB_0055d0d4;
LAB_0055cf38:
      unaff_s3 = asn1_do_adb((ASN1_VALUE **)piVar11,pAStack_94,1);
      if (unaff_s3 == (ASN1_TEMPLATE *)0x0) goto switchD_0055cc3c_caseD_7;
      ppAVar6 = (ASN1_TEMPLATE **)asn1_get_field_ptr((ASN1_VALUE **)piVar11,unaff_s3);
      unaff_s5 = unaff_s3->flags;
      if ((unaff_s5 & 0x18) == 0) {
        uVar5 = 0;
        lStack_90 = -1;
      }
      else {
        lStack_90 = unaff_s3->tag;
        uVar5 = unaff_s5 & 0xc0;
      }
      uVar16 = unaff_s5 & 6;
      iStack_88 = 1;
      if ((unaff_s5 & 0x800) != 0) {
        iStack_88 = iStack_80;
      }
      if (uVar16 != 0) {
        unaff_s2 = *ppAVar6;
        if (unaff_s2 == (ASN1_TEMPLATE *)0x0) {
          uVar5 = 0;
          goto LAB_0055d084;
        }
        if ((unaff_s5 & 2) == 0) {
          iStack_78 = 0x10;
          if (lStack_90 == -1) {
            iStack_78 = 0x10;
          }
          else if ((unaff_s5 & 0x10) == 0) {
            iStack_78 = lStack_90;
          }
        }
        else {
          iStack_78 = 0x11;
          if ((lStack_90 != -1) && ((unaff_s5 & 0x10) == 0)) {
            iStack_78 = lStack_90;
          }
        }
        goto LAB_0055cfd0;
      }
      unaff_s5 = unaff_s5 & 0x10;
      if (unaff_s5 == 0) {
        uVar5 = ASN1_item_ex_i2d((ASN1_VALUE **)ppAVar6,(uchar **)0x0,unaff_s3->item,lStack_90,
                                 unaff_s7 | uVar5);
        goto LAB_0055d084;
      }
      uVar5 = ASN1_item_ex_i2d((ASN1_VALUE **)ppAVar6,(uchar **)0x0,unaff_s3->item,-1,unaff_s7);
    } while (uVar5 == 0);
LAB_0055d1d8:
    uVar5 = ASN1_object_size(iStack_88,uVar5,lStack_90);
  } while( true );
LAB_0055d0d4:
  pAVar4 = (ASN1_ITEM *)ASN1_object_size(iStack_74,(int)pAStack_6c,(int)pAStack_2c);
  if (pp != (ASN1_TEMPLATE **)0x0) {
    if (pAVar4 == (ASN1_ITEM *)0xffffffff) {
LAB_0055d2f0:
      pAVar4 = (ASN1_ITEM *)0xffffffff;
    }
    else {
      ASN1_put_object((uchar **)pp,iStack_74,(int)pAStack_6c,(int)pAStack_2c,(int)local_28);
      pAVar18 = *(ASN1_TEMPLATE **)((int)putype + 8);
      if (0 < *(long *)((int)putype + 0xc)) {
        do {
          unaff_s2 = asn1_do_adb((ASN1_VALUE **)piVar11,pAVar18,1);
          if (unaff_s2 == (ASN1_TEMPLATE *)0x0) {
            pAVar4 = (ASN1_ITEM *)0x0;
            goto LAB_0055cc80;
          }
          pAVar18 = pAVar18 + 1;
          unaff_s3 = (ASN1_TEMPLATE *)((int)&pAStack_7c->flags + 1);
          ppAVar8 = asn1_get_field_ptr((ASN1_VALUE **)piVar11,unaff_s2);
          asn1_template_ex_i2d(ppAVar8,pp,unaff_s2,0xffffffff,local_28);
          pAStack_7c = unaff_s3;
        } while ((int)unaff_s3 < *(long *)((int)putype + 0xc));
      }
      if (iStack_74 == 2) {
        ASN1_put_eoc((uchar **)pp);
      }
      if ((pcStack_84 != (code *)0x0) && (iVar17 = (*pcStack_84)(7,piVar11,putype,0), iVar17 == 0))
      {
switchD_0055cc3c_caseD_7:
        pAVar4 = (ASN1_ITEM *)0x0;
      }
    }
  }
  goto LAB_0055cc80;
}

