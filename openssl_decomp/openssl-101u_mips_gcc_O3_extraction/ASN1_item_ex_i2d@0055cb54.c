
int ASN1_item_ex_i2d(ASN1_VALUE **pval,uchar **out,ASN1_ITEM *it,int tag,int aclass)

{
  bool bVar1;
  bool bVar2;
  undefined *puVar3;
  uint uVar4;
  int iVar5;
  ASN1_TEMPLATE **ppAVar6;
  int iVar7;
  ASN1_VALUE **ppAVar8;
  int **ppiVar9;
  ASN1_BIT_STRING *pAVar10;
  ASN1_VALUE *pAVar11;
  int *piVar12;
  void *pvVar13;
  uchar *puVar14;
  byte *pbVar15;
  uint uVar16;
  int iVar17;
  ASN1_TEMPLATE *pAVar18;
  ASN1_TEMPLATE *unaff_s2;
  ASN1_TEMPLATE *unaff_s3;
  uint unaff_s5;
  uint unaff_s7;
  code *pcVar19;
  int local_resc;
  ASN1_TEMPLATE *local_5c;
  long local_58;
  int local_54;
  int local_50;
  code *local_4c;
  int local_48;
  ASN1_TEMPLATE *local_44;
  int local_40;
  int local_3c;
  uchar local_35;
  int local_34;
  ASN1_TEMPLATE *local_30;
  int local_2c;
  
  puVar3 = PTR___stack_chk_guard_006a9ae8;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  uVar4 = (uint)it->itype;
  pvVar13 = it->funcs;
  local_resc = tag;
  if (uVar4 != 0) {
    pAVar11 = *pval;
    if (pAVar11 == (ASN1_VALUE *)0x0) goto switchD_0055cc3c_caseD_7;
    if ((pvVar13 == (void *)0x0) ||
       (local_4c = *(code **)((int)pvVar13 + 0x10), local_4c == (code *)0x0)) goto LAB_0055cc1c;
    switch(uVar4 & 0xff) {
    default:
      goto switchD_0055cc3c_caseD_7;
    case 1:
      local_3c = 1;
      break;
    case 2:
      iVar5 = (*local_4c)(6,pval,it,0);
      if (iVar5 == 0) goto switchD_0055cc3c_caseD_7;
      iVar5 = asn1_get_choice_selector(pval,it);
      if ((iVar5 < 0) || (it->tcount <= iVar5)) {
        (*local_4c)(7,pval,it,0);
        iVar5 = 0;
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
  if ((pvVar13 != (void *)0x0) && (*(int *)((int)pvVar13 + 0x10) == 0)) {
LAB_0055cc1c:
    switch(uVar4 & 0xff) {
    case 0:
      goto switchD_0055cc3c_caseD_0;
    case 1:
      local_4c = (code *)0x0;
      local_3c = 1;
      break;
    case 2:
      iVar5 = asn1_get_choice_selector(pval,it);
      if (iVar5 < 0) goto switchD_0055cc3c_caseD_7;
      if (it->tcount <= iVar5) goto switchD_0055cc3c_caseD_7;
LAB_0055d2a4:
      pAVar18 = it->templates;
      ppAVar8 = asn1_get_field_ptr(pval,pAVar18 + iVar5);
      iVar5 = asn1_template_ex_i2d(ppAVar8,out,pAVar18 + iVar5,0xffffffff,aclass);
      goto LAB_0055cc80;
    case 3:
      pAVar11 = *pval;
switchD_0055cc00_caseD_3:
      if (out == (uchar **)0x0) {
        iVar5 = (**(code **)((int)pvVar13 + 0xc))(pAVar11,0);
      }
      else {
        pbVar15 = *out;
        iVar5 = (**(code **)((int)pvVar13 + 0xc))(pAVar11,out);
        if (tag != -1) {
          *pbVar15 = *pbVar15 & 0x20 | (byte)aclass | (byte)tag;
        }
      }
      goto LAB_0055cc80;
    case 4:
switchD_0055cc3c_caseD_4:
      iVar5 = (**(code **)((int)pvVar13 + 0x14))(pval,out,it,tag,aclass);
      goto LAB_0055cc80;
    case 5:
switchD_0055cc3c_caseD_5:
      local_30 = (ASN1_TEMPLATE *)it->utype;
      unaff_s2 = (ASN1_TEMPLATE *)&local_30;
      iVar5 = asn1_ex_i2c(pval,(uchar *)0x0,(int *)unaff_s2,it);
      unaff_s3 = local_30;
      bVar1 = &SUB_00000002 <= &local_30[-1].tag;
      bVar2 = local_30 != (ASN1_TEMPLATE *)0xfffffffd;
      if (iVar5 == -1) goto switchD_0055cc3c_caseD_7;
      unaff_s5 = 2;
      if (iVar5 == -2) {
        iVar5 = 0;
      }
      else {
        unaff_s5 = 0;
      }
      if (out == (uchar **)0x0) {
LAB_0055ce5c:
        if (!bVar1 || !bVar2) goto LAB_0055cc80;
      }
      else {
        if (bVar1 && bVar2) {
          ASN1_put_object(out,unaff_s5,iVar5,(int)local_30,aclass);
        }
        asn1_ex_i2c(pval,*out,(int *)unaff_s2,it);
        if (unaff_s5 == 0) {
          *out = *out + iVar5;
          goto LAB_0055ce5c;
        }
        ASN1_put_eoc(out);
        if (!bVar1 || !bVar2) goto LAB_0055cc80;
      }
      iVar5 = ASN1_object_size(unaff_s5,iVar5,(int)unaff_s3);
      goto LAB_0055cc80;
    case 6:
      local_4c = (code *)0x0;
switchD_0055cc00_caseD_6:
      local_3c = 1;
      if ((aclass & 0x800U) != 0) {
        local_3c = 2;
      }
      break;
    default:
      goto switchD_0055cc3c_caseD_7;
    }
LAB_0055cd90:
    local_44 = (ASN1_TEMPLATE *)asn1_enc_restore(&local_34,out,pval,it);
    if ((int)local_44 < 0) goto switchD_0055cc3c_caseD_7;
    iVar5 = local_34;
    if (local_44 == (ASN1_TEMPLATE *)0x0) {
      local_34 = 0;
      if (tag == -1) {
        local_resc = 0x10;
        aclass = aclass & 0xffffff3f;
      }
      if ((local_4c != (code *)0x0) && (iVar5 = (*local_4c)(6,pval,it,0), iVar5 == 0))
      goto switchD_0055cc3c_caseD_7;
      local_5c = it->templates;
      if (it->tcount < 1) goto LAB_0055d0d4;
      local_54 = 0;
      local_48 = 1;
      if ((aclass & 0x800U) != 0) {
        local_48 = 2;
      }
      unaff_s7 = aclass & 0xffffff3f;
      goto LAB_0055cf38;
    }
    goto LAB_0055cc80;
  }
switchD_0055cc3c_caseD_0:
  if (it->templates != (ASN1_TEMPLATE *)0x0) {
    iVar5 = asn1_template_ex_i2d(pval,out,it->templates,tag,aclass);
    goto LAB_0055cc80;
  }
  iVar17 = it->utype;
  local_34 = iVar17;
  if (pvVar13 != (void *)0x0) {
    if (*(code **)((int)pvVar13 + 0x18) == (code *)0x0) goto LAB_0055d5c0;
    iVar5 = (**(code **)((int)pvVar13 + 0x18))(pval,0,&local_34,it);
    goto LAB_0055d3a8;
  }
LAB_0055d5c0:
  ppiVar9 = (int **)pval;
  if (iVar17 == 1) {
switchD_0055d604_caseD_1:
    iVar5 = -1;
    if (*ppiVar9 == (int *)0xffffffff) {
      iVar7 = 1;
    }
    else {
      iVar5 = 1;
      if (iVar17 == -4) {
        iVar7 = 1;
      }
      else {
        iVar5 = 1;
        if (*ppiVar9 == (int *)0x0) {
          iVar7 = 1;
          if (it->size == 0) {
            iVar5 = -1;
          }
        }
        else {
          iVar5 = 1;
          iVar7 = 1;
          if (0 < it->size) {
            iVar5 = -1;
          }
        }
      }
    }
    goto LAB_0055d3b8;
  }
  piVar12 = (int *)*pval;
  iVar7 = iVar17;
  if (piVar12 == (int *)0x0) {
    if (iVar17 - 0x10U < 2) goto switchD_0055cc3c_caseD_7;
    iVar5 = -1;
    goto LAB_0055d3b8;
  }
  if (iVar17 == -4) {
    ppiVar9 = (int **)(piVar12 + 1);
    iVar7 = *piVar12;
  }
  local_34 = iVar7;
  switch(iVar7) {
  default:
    if ((it->size != 0x800) || (((*ppiVar9)[3] & 0x10U) == 0)) {
      iVar5 = **ppiVar9;
      goto LAB_0055d3a8;
    }
    bVar1 = false;
    if (1 < iVar7 - 0x10U) {
      iVar5 = -2;
      break;
    }
    goto LAB_0055d6c4;
  case 1:
    goto switchD_0055d604_caseD_1;
  case 2:
  case 10:
    pcVar19 = (code *)PTR_i2c_ASN1_INTEGER_006a8d8c;
    goto LAB_0055d618;
  case 3:
    pcVar19 = (code *)PTR_i2c_ASN1_BIT_STRING_006a8d88;
LAB_0055d618:
    iVar5 = (*pcVar19)(*ppiVar9,0);
LAB_0055d3a8:
    bVar1 = false;
    iVar7 = local_34;
    if (1 < local_34 - 0x10U) break;
    goto LAB_0055d3c0;
  case 5:
    iVar5 = 0;
    break;
  case 6:
    iVar5 = (*ppiVar9)[3];
  }
LAB_0055d3b8:
  bVar1 = iVar7 != -3;
LAB_0055d3c0:
  if (iVar5 == -1) goto switchD_0055cc3c_caseD_7;
  if (iVar5 == -2) {
LAB_0055d6c4:
    unaff_s2 = (ASN1_TEMPLATE *)&SUB_00000002;
    iVar5 = 0;
  }
  else {
    unaff_s2 = (ASN1_TEMPLATE *)0x0;
  }
  if (tag == -1) {
    local_resc = iVar7;
  }
  if (out != (uchar **)0x0) {
    if (bVar1) {
      ASN1_put_object(out,(int)unaff_s2,iVar5,local_resc,aclass);
    }
    local_30 = (ASN1_TEMPLATE *)*out;
    if ((it->funcs == (void *)0x0) ||
       (pcVar19 = *(code **)((int)it->funcs + 0x18), pcVar19 == (code *)0x0)) {
      if (it->itype == '\0') {
        iVar17 = it->utype;
        if (iVar17 != 1) {
          piVar12 = (int *)*pval;
          if (piVar12 == (int *)0x0) goto switchD_0055d4b4_caseD_5;
LAB_0055d488:
          if (iVar17 == -4) {
            local_34 = *piVar12;
            pval = (ASN1_VALUE **)(piVar12 + 1);
          }
        }
      }
      else {
        piVar12 = (int *)*pval;
        if (piVar12 == (int *)0x0) goto switchD_0055d4b4_caseD_5;
        if (it->itype != '\x05') {
          iVar17 = it->utype;
          goto LAB_0055d488;
        }
        local_34 = piVar12[1];
      }
      switch(local_34) {
      default:
        pAVar10 = (ASN1_BIT_STRING *)*pval;
        if ((it->size != 0x800) || ((pAVar10->flags & 0x10U) == 0)) {
          puVar14 = pAVar10->data;
          iVar17 = pAVar10->length;
          goto LAB_0055d4d8;
        }
        if (local_30 != (ASN1_TEMPLATE *)0x0) {
          pAVar10->data = (uchar *)local_30;
          pAVar10->length = 0;
        }
        break;
      case 1:
        pAVar10 = (ASN1_BIT_STRING *)*pval;
        if (pAVar10 != (ASN1_BIT_STRING *)0xffffffff) {
          if (it->utype != -4) {
            if (pAVar10 == (ASN1_BIT_STRING *)0x0) {
              if (it->size != 0) goto LAB_0055d56c;
            }
            else if (it->size < 1) goto LAB_0055d56c;
            break;
          }
LAB_0055d56c:
          local_35 = (uchar)pAVar10;
          if (local_30 == (ASN1_TEMPLATE *)0x0) break;
          iVar17 = 1;
          puVar14 = &local_35;
          goto LAB_0055d4e8;
        }
        break;
      case 2:
      case 10:
        if (local_30 == (ASN1_TEMPLATE *)0x0) {
          ppAVar6 = (ASN1_TEMPLATE **)0x0;
        }
        else {
          ppAVar6 = &local_30;
        }
        i2c_ASN1_INTEGER((ASN1_INTEGER *)*pval,(uchar **)ppAVar6);
        break;
      case 3:
        if (local_30 == (ASN1_TEMPLATE *)0x0) {
          ppAVar6 = (ASN1_TEMPLATE **)0x0;
        }
        else {
          ppAVar6 = &local_30;
        }
        i2c_ASN1_BIT_STRING((ASN1_BIT_STRING *)*pval,(uchar **)ppAVar6);
        break;
      case 5:
        break;
      case 6:
        puVar14 = (uchar *)((ASN1_BIT_STRING *)*pval)[1].length;
        iVar17 = ((ASN1_BIT_STRING *)*pval)->flags;
LAB_0055d4d8:
        if ((local_30 != (ASN1_TEMPLATE *)0x0) && (iVar17 != 0)) {
LAB_0055d4e8:
          (*(code *)PTR_memcpy_006a9aec)(local_30,puVar14,iVar17);
        }
      }
    }
    else {
      (*pcVar19)(pval,local_30,&local_34,it);
    }
switchD_0055d4b4_caseD_5:
    if (unaff_s2 == (ASN1_TEMPLATE *)0x0) {
      *out = *out + iVar5;
    }
    else {
      ASN1_put_eoc(out);
    }
  }
  if (bVar1) {
    iVar5 = ASN1_object_size((int)unaff_s2,iVar5,local_resc);
  }
LAB_0055cc80:
  if (local_2c == *(int *)puVar3) {
    return iVar5;
  }
  local_40 = (*(code *)PTR___stack_chk_fail_006a9ab0)();
LAB_0055cfd0:
  iVar17 = 0;
  for (iVar5 = 0; iVar7 = (*(code *)PTR_sk_num_006a6e2c)(unaff_s2), iVar5 < iVar7; iVar5 = iVar5 + 1
      ) {
    local_30 = (ASN1_TEMPLATE *)(*(code *)PTR_sk_value_006a6e24)(unaff_s2,iVar5);
    iVar7 = ASN1_item_ex_i2d((ASN1_VALUE **)&local_30,(uchar **)0x0,unaff_s3->item,-1,unaff_s7);
    if ((iVar7 == -1) || (bVar1 = 0x7fffffff - iVar7 < iVar17, iVar17 = iVar17 + iVar7, bVar1))
    goto LAB_0055d204;
  }
  uVar4 = ASN1_object_size(local_50,iVar17,local_40);
  if (uVar4 == 0xffffffff) {
LAB_0055d204:
    uVar4 = 0xffffffff;
  }
  else {
    unaff_s5 = unaff_s5 & 0x10;
    if (unaff_s5 != 0) goto LAB_0055d1d8;
  }
LAB_0055d084:
  do {
    iVar5 = -1;
    uVar16 = uVar4;
    if (uVar4 == 0xffffffff) goto LAB_0055cc80;
    do {
      if (0x7fffffff - local_34 < (int)uVar16) goto LAB_0055d2f0;
      local_34 = local_34 + uVar16;
      local_54 = local_54 + 1;
      local_5c = local_5c + 1;
      if (it->tcount <= local_54) goto LAB_0055d0d4;
LAB_0055cf38:
      unaff_s3 = asn1_do_adb(pval,local_5c,1);
      if (unaff_s3 == (ASN1_TEMPLATE *)0x0) goto switchD_0055cc3c_caseD_7;
      ppAVar6 = (ASN1_TEMPLATE **)asn1_get_field_ptr(pval,unaff_s3);
      unaff_s5 = unaff_s3->flags;
      if ((unaff_s5 & 0x18) == 0) {
        uVar4 = 0;
        local_58 = -1;
      }
      else {
        local_58 = unaff_s3->tag;
        uVar4 = unaff_s5 & 0xc0;
      }
      uVar16 = unaff_s5 & 6;
      local_50 = 1;
      if ((unaff_s5 & 0x800) != 0) {
        local_50 = local_48;
      }
      if (uVar16 != 0) {
        unaff_s2 = *ppAVar6;
        if (unaff_s2 == (ASN1_TEMPLATE *)0x0) {
          uVar4 = 0;
          goto LAB_0055d084;
        }
        if ((unaff_s5 & 2) == 0) {
          local_40 = 0x10;
          if (local_58 == -1) {
            local_40 = 0x10;
          }
          else if ((unaff_s5 & 0x10) == 0) {
            local_40 = local_58;
          }
        }
        else {
          local_40 = 0x11;
          if ((local_58 != -1) && ((unaff_s5 & 0x10) == 0)) {
            local_40 = local_58;
          }
        }
        goto LAB_0055cfd0;
      }
      unaff_s5 = unaff_s5 & 0x10;
      if (unaff_s5 == 0) {
        uVar4 = ASN1_item_ex_i2d((ASN1_VALUE **)ppAVar6,(uchar **)0x0,unaff_s3->item,local_58,
                                 unaff_s7 | uVar4);
        goto LAB_0055d084;
      }
      uVar4 = ASN1_item_ex_i2d((ASN1_VALUE **)ppAVar6,(uchar **)0x0,unaff_s3->item,-1,unaff_s7);
    } while (uVar4 == 0);
LAB_0055d1d8:
    uVar4 = ASN1_object_size(local_50,uVar4,local_58);
  } while( true );
LAB_0055d0d4:
  iVar5 = ASN1_object_size(local_3c,local_34,local_resc);
  if (out != (uchar **)0x0) {
    if (iVar5 == -1) {
LAB_0055d2f0:
      iVar5 = -1;
    }
    else {
      ASN1_put_object(out,local_3c,local_34,local_resc,aclass);
      pAVar18 = it->templates;
      if (0 < it->tcount) {
        do {
          unaff_s2 = asn1_do_adb(pval,pAVar18,1);
          if (unaff_s2 == (ASN1_TEMPLATE *)0x0) {
            iVar5 = 0;
            goto LAB_0055cc80;
          }
          pAVar18 = pAVar18 + 1;
          unaff_s3 = (ASN1_TEMPLATE *)((int)&local_44->flags + 1);
          ppAVar8 = asn1_get_field_ptr(pval,unaff_s2);
          asn1_template_ex_i2d(ppAVar8,out,unaff_s2,0xffffffff,aclass);
          local_44 = unaff_s3;
        } while ((int)unaff_s3 < it->tcount);
      }
      if (local_3c == 2) {
        ASN1_put_eoc(out);
      }
      if ((local_4c != (code *)0x0) && (iVar17 = (*local_4c)(7,pval,it,0), iVar17 == 0)) {
switchD_0055cc3c_caseD_7:
        iVar5 = 0;
      }
    }
  }
  goto LAB_0055cc80;
}

