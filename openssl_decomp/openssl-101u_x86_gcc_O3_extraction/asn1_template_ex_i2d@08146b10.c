
/* WARNING: Type propagation algorithm not settling */

uint __regparm3
asn1_template_ex_i2d(_STACK **param_1_00,uchar **param_2_00,uint *param_3,uint param_1,uint param_2)

{
  uchar **ppuVar1;
  byte bVar2;
  uint uVar3;
  _STACK *p_Var4;
  ASN1_ITEM *pAVar5;
  void *pvVar6;
  uint aclass;
  int iVar7;
  int iVar8;
  uint length;
  uchar *puVar9;
  int iVar10;
  ASN1_TEMPLATE *tt;
  uchar **ptr;
  uchar *puVar11;
  size_t __nmemb;
  uchar **ppuVar12;
  code *pcVar13;
  ASN1_TEMPLATE *tt_00;
  int in_GS_OFFSET;
  bool bVar14;
  uchar *local_68;
  int local_54;
  uint local_50;
  uint local_4c;
  int local_48;
  uint local_40;
  int local_3c;
  uint local_38;
  ASN1_VALUE *local_2c;
  ASN1_VALUE *local_28;
  uchar *local_24;
  int local_20;
  
  uVar3 = *param_3;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if ((uVar3 & 0x18) == 0) {
    local_50 = uVar3 & 0x18;
    if (param_1 != 0xffffffff) {
      local_50 = param_2 & 0xc0;
    }
LAB_08146b74:
    local_54 = 1;
    aclass = param_2 & 0xffffff3f;
    if ((uVar3 & 0x800) != 0) {
      local_54 = 2 - (uint)((param_2 & 0x800) == 0);
    }
    local_4c = uVar3 & 6;
    if (local_4c == 0) {
      if ((uVar3 & 0x10) == 0) {
        local_4c = ASN1_item_ex_i2d((ASN1_VALUE **)param_1_00,param_2_00,(ASN1_ITEM *)param_3[4],
                                    param_1,local_50 | aclass);
        goto LAB_08146c28;
      }
      iVar7 = ASN1_item_ex_i2d((ASN1_VALUE **)param_1_00,(uchar **)0x0,(ASN1_ITEM *)param_3[4],-1,
                               aclass);
      if (((iVar7 == 0) ||
          (local_4c = ASN1_object_size(local_54,iVar7,param_1), param_2_00 == (uchar **)0x0)) ||
         (local_4c == 0xffffffff)) goto LAB_08146c28;
      ASN1_put_object(param_2_00,local_54,iVar7,param_1,local_50);
      ASN1_item_ex_i2d((ASN1_VALUE **)param_1_00,param_2_00,(ASN1_ITEM *)param_3[4],-1,aclass);
      if (local_54 != 2) goto LAB_08146c28;
    }
    else {
      p_Var4 = *param_1_00;
      if (p_Var4 == (_STACK *)0x0) {
        local_4c = 0;
        goto LAB_08146c28;
      }
      if ((uVar3 & 2) == 0) {
        if (param_1 == 0xffffffff) {
          local_3c = 0;
          local_38 = 0;
          local_40 = 0x10;
        }
        else {
          local_3c = 0;
          bVar14 = (uVar3 & 0x10) == 0;
          local_38 = uVar3 & 2;
          if (bVar14) {
            local_38 = local_50;
          }
          local_40 = 0x10;
          if (bVar14) {
            local_40 = param_1;
          }
        }
      }
      else {
        local_3c = 2 - (uint)((uVar3 & 4) == 0);
        if (param_1 == 0xffffffff) {
          local_38 = 0;
          local_40 = 0x11;
        }
        else {
          local_38 = 0;
          local_40 = 0x11;
          if ((uVar3 & 0x10) == 0) {
            local_40 = param_1;
            local_38 = local_50;
          }
        }
      }
      local_68 = (uchar *)0x0;
      iVar7 = sk_num(p_Var4);
      if (0 < iVar7) {
        iVar7 = 0;
        do {
          local_2c = (ASN1_VALUE *)sk_value(p_Var4,iVar7);
          pAVar5 = (ASN1_ITEM *)param_3[4];
          pvVar6 = pAVar5->funcs;
          bVar2 = pAVar5->itype;
          if ((local_2c == (ASN1_VALUE *)0x0) && (bVar2 != 0)) goto switchD_08146fc5_caseD_7;
          if (pvVar6 == (void *)0x0) {
            switch(bVar2) {
            case 0:
              goto switchD_08146fc5_caseD_0;
            case 1:
              pcVar13 = (code *)0x0;
              goto switchD_08146d1e_caseD_1;
            case 2:
switchD_08146fc5_caseD_2:
              iVar8 = asn1_get_choice_selector(&local_2c,pAVar5);
              if (iVar8 < 0) goto switchD_08146fc5_caseD_7;
              if (iVar8 < pAVar5->tcount) {
LAB_08146f65:
                asn1_get_field_ptr(&local_2c,pAVar5->templates + iVar8);
                puVar9 = (uchar *)asn1_template_ex_i2d(0xffffffff,aclass);
                goto LAB_08146d41;
              }
              puVar9 = (uchar *)0x0;
              break;
            case 3:
              goto switchD_08146fc5_caseD_3;
            case 4:
              goto switchD_08146fc5_caseD_4;
            case 5:
              goto switchD_08146fc5_caseD_5;
            case 6:
              pcVar13 = (code *)0x0;
              goto switchD_08146d1e_caseD_6;
            default:
              goto switchD_08146fc5_caseD_7;
            }
            goto LAB_08146d5b;
          }
          pcVar13 = *(code **)((int)pvVar6 + 0x10);
          switch(bVar2) {
          case 0:
switchD_08146fc5_caseD_0:
            if (pAVar5->templates == (ASN1_TEMPLATE *)0x0) goto switchD_08146fc5_caseD_5;
            puVar9 = (uchar *)asn1_template_ex_i2d(0xffffffff,aclass);
            break;
          case 1:
switchD_08146d1e_caseD_1:
            local_48 = 1;
            goto LAB_08146e78;
          case 2:
            if (pcVar13 == (code *)0x0) goto switchD_08146fc5_caseD_2;
            iVar8 = (*pcVar13)(6,&local_2c,pAVar5,0);
            if (iVar8 != 0) {
              iVar8 = asn1_get_choice_selector(&local_2c,pAVar5);
              if ((-1 < iVar8) && (iVar8 < pAVar5->tcount)) goto LAB_08146f65;
              (*pcVar13)(7,&local_2c,pAVar5,0);
            }
          default:
switchD_08146fc5_caseD_7:
            puVar9 = (uchar *)0x0;
            goto LAB_08146d5b;
          case 3:
switchD_08146fc5_caseD_3:
            puVar9 = (uchar *)(**(code **)((int)pvVar6 + 0xc))(local_2c,0);
            break;
          case 4:
switchD_08146fc5_caseD_4:
            puVar9 = (uchar *)(**(code **)((int)pvVar6 + 0x14))
                                        (&local_2c,0,pAVar5,0xffffffff,aclass);
            break;
          case 5:
switchD_08146fc5_caseD_5:
            puVar9 = (uchar *)asn1_i2d_ex_primitive(0xffffffff,aclass);
            break;
          case 6:
switchD_08146d1e_caseD_6:
            local_48 = 2 - (uint)((param_2 & 0x800) == 0);
LAB_08146e78:
            iVar8 = asn1_enc_restore((int *)&local_24,(uchar **)0x0,&local_2c,pAVar5);
            if (iVar8 < 0) goto switchD_08146fc5_caseD_7;
            puVar9 = local_24;
            if (iVar8 == 0) {
              local_24 = (uchar *)0x0;
              if ((pcVar13 != (code *)0x0) &&
                 (iVar10 = (*pcVar13)(6,&local_2c,pAVar5,0), iVar10 == 0))
              goto switchD_08146fc5_caseD_7;
              tt_00 = pAVar5->templates;
              if (0 < pAVar5->tcount) {
                do {
                  tt = asn1_do_adb(&local_2c,tt_00,1);
                  if (tt == (ASN1_TEMPLATE *)0x0) {
                    puVar9 = (uchar *)0x0;
                    goto LAB_08146d5b;
                  }
                  asn1_get_field_ptr(&local_2c,tt);
                  iVar10 = asn1_template_ex_i2d(0xffffffff,aclass);
                  if ((iVar10 == -1) || (0x7fffffff - (int)local_24 < iVar10)) goto LAB_08146c48;
                  local_24 = local_24 + iVar10;
                  tt_00 = tt_00 + 1;
                  iVar8 = iVar8 + 1;
                } while (iVar8 < pAVar5->tcount);
              }
              puVar9 = (uchar *)ASN1_object_size(local_48,(int)local_24,0x10);
            }
          }
LAB_08146d41:
          if ((puVar9 == (uchar *)0xffffffff) || (0x7fffffff - (int)puVar9 < (int)local_68))
          goto LAB_08146c48;
LAB_08146d5b:
          local_68 = local_68 + (int)puVar9;
          iVar7 = iVar7 + 1;
          iVar8 = sk_num(p_Var4);
        } while (iVar7 < iVar8);
      }
      length = ASN1_object_size(local_54,(int)local_68,local_40);
      if (length == 0xffffffff) goto LAB_08146c48;
      if ((uVar3 & 0x10) == 0) {
        local_4c = length;
        if (param_2_00 == (uchar **)0x0) goto LAB_08146c28;
      }
      else {
        local_4c = ASN1_object_size(local_54,length,param_1);
        if ((param_2_00 == (uchar **)0x0) || (local_4c == 0xffffffff)) goto LAB_08146c28;
        ASN1_put_object(param_2_00,local_54,length,param_1,local_50);
      }
      ASN1_put_object(param_2_00,local_54,(int)local_68,local_40,local_38);
      local_24 = (uchar *)0x0;
      pAVar5 = (ASN1_ITEM *)param_3[4];
      if ((local_3c == 0) || (iVar7 = sk_num(p_Var4), iVar7 < 2)) {
        for (iVar7 = 0; iVar8 = sk_num(p_Var4), iVar7 < iVar8; iVar7 = iVar7 + 1) {
          local_28 = (ASN1_VALUE *)sk_value(p_Var4,iVar7);
          ASN1_item_ex_i2d(&local_28,param_2_00,pAVar5,-1,aclass);
        }
      }
      else {
        iVar7 = sk_num(p_Var4);
        ptr = (uchar **)CRYPTO_malloc(iVar7 * 0xc,"tasn_enc.c",0x1ba);
        if (ptr != (uchar **)0x0) {
          puVar9 = (uchar *)CRYPTO_malloc((int)local_68,"tasn_enc.c",0x1bd);
          if (puVar9 == (uchar *)0x0) {
            CRYPTO_free(ptr);
          }
          else {
            ppuVar12 = ptr;
            local_24 = puVar9;
            for (iVar7 = 0; iVar8 = sk_num(p_Var4), iVar7 < iVar8; iVar7 = iVar7 + 1) {
              local_28 = (ASN1_VALUE *)sk_value(p_Var4,iVar7);
              *ppuVar12 = local_24;
              puVar11 = (uchar *)ASN1_item_ex_i2d(&local_28,&local_24,pAVar5,-1,aclass);
              ppuVar12[1] = puVar11;
              ppuVar12[2] = (uchar *)local_28;
              ppuVar12 = ppuVar12 + 3;
            }
            __nmemb = sk_num(p_Var4);
            qsort(ptr,__nmemb,0xc,der_cmp);
            local_24 = *param_2_00;
            ppuVar12 = ptr;
            for (iVar7 = 0; iVar8 = sk_num(p_Var4), iVar7 < iVar8; iVar7 = iVar7 + 1) {
              memcpy(local_24,*ppuVar12,(size_t)ppuVar12[1]);
              local_24 = local_24 + (int)ppuVar12[1];
              ppuVar12 = ppuVar12 + 3;
            }
            *param_2_00 = local_24;
            if (local_3c == 2) {
              ppuVar12 = ptr;
              for (iVar7 = 0; iVar8 = sk_num(p_Var4), iVar7 < iVar8; iVar7 = iVar7 + 1) {
                ppuVar1 = ppuVar12 + 2;
                ppuVar12 = ppuVar12 + 3;
                sk_set(p_Var4,iVar7,*ppuVar1);
              }
            }
            CRYPTO_free(ptr);
            CRYPTO_free(puVar9);
          }
        }
      }
      if ((local_54 != 2) || (ASN1_put_eoc(param_2_00), (uVar3 & 0x10) == 0)) goto LAB_08146c28;
    }
    ASN1_put_eoc(param_2_00);
  }
  else {
    if (param_1 == 0xffffffff) {
      param_1 = param_3[1];
      local_50 = uVar3 & 0xc0;
      goto LAB_08146b74;
    }
LAB_08146c48:
    local_4c = 0xffffffff;
  }
LAB_08146c28:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return local_4c;
}

