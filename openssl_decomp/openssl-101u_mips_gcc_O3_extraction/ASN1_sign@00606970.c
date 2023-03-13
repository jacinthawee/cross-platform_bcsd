
int ASN1_sign(undefined1 *i2d,X509_ALGOR *algor1,X509_ALGOR *algor2,ASN1_BIT_STRING *signature,
             char *data,EVP_PKEY *pkey,EVP_MD *type)

{
  ASN1_TYPE *pAVar1;
  ASN1_OBJECT *pAVar2;
  int iVar3;
  EVP_PKEY_ASN1_METHOD *pEVar4;
  EVP_PKEY *pEVar5;
  EVP_MD_CTX *pEVar6;
  int *piVar7;
  undefined4 uVar8;
  int iVar9;
  int iVar10;
  int *piVar11;
  undefined4 *puVar12;
  ASN1_BIT_STRING *pAVar13;
  undefined4 uVar14;
  char *pcVar15;
  undefined4 unaff_s4;
  ASN1_BIT_STRING *unaff_s5;
  code *pcVar16;
  undefined *puVar17;
  int iStack_288;
  int iStack_284;
  undefined4 uStack_280;
  undefined auStack_27c [24];
  int iStack_264;
  undefined *puStack_260;
  undefined *puStack_25c;
  int iStack_258;
  code *pcStack_254;
  EVP_PKEY *pEStack_250;
  EVP_PKEY *pEStack_24c;
  EVP_PKEY *pEStack_248;
  code *pcStack_244;
  int iStack_230;
  undefined *puStack_228;
  char *pcStack_21c;
  int iStack_218;
  undefined auStack_214 [24];
  int *piStack_1fc;
  undefined *puStack_1f8;
  char *pcStack_1f4;
  char *pcStack_1f0;
  EVP_PKEY *pEStack_1ec;
  X509_ALGOR *pXStack_1e8;
  undefined4 uStack_1e4;
  EVP_PKEY *pEStack_1e0;
  ASN1_BIT_STRING *pAStack_1dc;
  EVP_PKEY *pEStack_1d8;
  undefined4 uStack_1d4;
  char *pcStack_1c0;
  undefined4 uStack_1bc;
  undefined *puStack_1b8;
  int iStack_1b0;
  code *pcStack_1ac;
  EVP_MD_CTX *pEStack_1a4;
  undefined *puStack_1a0;
  char *pcStack_19c;
  code *pcStack_198;
  code *pcStack_194;
  EVP_PKEY *pEStack_180;
  undefined4 uStack_17c;
  undefined *puStack_178;
  EVP_MD_CTX *pEStack_170;
  EVP_PKEY *pEStack_16c;
  EVP_MD_CTX *pEStack_168;
  int iStack_164;
  undefined *puStack_160;
  ASN1_ITEM *pAStack_15c;
  EVP_PKEY *pEStack_158;
  X509_ALGOR *pXStack_154;
  EVP_PKEY *pEStack_150;
  char *pcStack_14c;
  EVP_PKEY *pEStack_148;
  undefined4 uStack_144;
  EVP_MD_CTX EStack_11c;
  code *pcStack_104;
  int iStack_100;
  EVP_PKEY *pEStack_fc;
  undefined *puStack_f8;
  EVP_PKEY *pEStack_f4;
  char *pcStack_f0;
  EVP_PKEY *pEStack_ec;
  X509_ALGOR *pXStack_e8;
  ASN1_BIT_STRING *pAStack_e4;
  EVP_PKEY *pEStack_e0;
  code *pcStack_dc;
  EVP_PKEY *pEStack_c8;
  EVP_PKEY *pEStack_c4;
  X509_ALGOR *pXStack_c0;
  int iStack_b8;
  X509_ALGOR XStack_b4;
  ASN1_ITEM *pAStack_ac;
  EVP_MD *pEStack_a8;
  EVP_PKEY *pEStack_a4;
  X509_ALGOR *pXStack_a0;
  undefined *puStack_9c;
  undefined4 uStack_98;
  ASN1_BIT_STRING *pAStack_94;
  undefined *puStack_90;
  ASN1_BIT_STRING *pAStack_8c;
  char *pcStack_88;
  code *pcStack_84;
  X509_ALGOR *local_70;
  int iStack_6c;
  undefined *local_68;
  code *local_5c;
  EVP_PKEY *local_58;
  ASN1_BIT_STRING *local_54;
  X509_ALGOR *local_4c;
  undefined local_48 [28];
  EVP_PKEY *local_2c;
  
  puStack_90 = PTR___stack_chk_guard_006a9ae8;
  puStack_9c = local_48 + 4;
  local_58 = pkey;
  local_68 = &_gp;
  local_48._0_4_ = (ASN1_BIT_STRING *)0x0;
  local_2c = *(EVP_PKEY **)PTR___stack_chk_guard_006a9ae8;
  pAStack_e4 = (ASN1_BIT_STRING *)algor1;
  pEStack_e0 = (EVP_PKEY *)algor2;
  local_5c = (code *)i2d;
  local_54 = signature;
  (*(code *)PTR_EVP_MD_CTX_init_006a6e1c)(puStack_9c);
  pcStack_f0 = (char *)signature;
  if (algor1 == (X509_ALGOR *)0x0) {
    algor1 = (X509_ALGOR *)&DAT_00000005;
    if (algor2 != (X509_ALGOR *)0x0) {
      pAStack_8c = (ASN1_BIT_STRING *)0x1;
      unaff_s4 = 1;
      unaff_s5 = (ASN1_BIT_STRING *)&SUB_00000002;
      puVar17 = local_68;
      do {
        if (pAStack_8c != (ASN1_BIT_STRING *)0x1) {
          if (type->pkey_type == 0x71) {
            (**(code **)(puVar17 + -0x7948))(algor2->parameter);
            algor2->parameter = (ASN1_TYPE *)0x0;
            puVar17 = local_68;
          }
          else if ((algor2->parameter == (ASN1_TYPE *)0x0) || (algor2->parameter->type != 5)) {
            (**(code **)(puVar17 + -0x7948))();
            pAVar1 = (ASN1_TYPE *)(**(code **)(local_68 + -0x6f14))();
            algor2->parameter = pAVar1;
            if (pAVar1 == (ASN1_TYPE *)0x0) goto LAB_00606e3c;
            pAVar1->type = 5;
            puVar17 = local_68;
          }
          (**(code **)(puVar17 + -0x7ddc))(algor2->algorithm);
          pAVar2 = (ASN1_OBJECT *)(**(code **)(local_68 + -0x7ca0))(type->pkey_type);
          algor2->algorithm = pAVar2;
          if (pAVar2 == (ASN1_OBJECT *)0x0) goto LAB_00606e8c;
          pcStack_f0 = (char *)0x680000;
          if (pAVar2->length == 0) goto LAB_00606e18;
          puVar17 = local_68;
          if (pAStack_8c == (ASN1_BIT_STRING *)&SUB_00000002) break;
        }
        pAStack_8c = (ASN1_BIT_STRING *)((int)&pAStack_8c->length + 1);
      } while( true );
    }
LAB_00606a9c:
    unaff_s4 = 0x680000;
    pAStack_8c = (ASN1_BIT_STRING *)(*local_5c)(data,0);
    algor1 = (X509_ALGOR *)(**(code **)(local_68 + -0x7dd8))(pAStack_8c,s_a_sign_c_00679744,0xae);
    unaff_s5 = (ASN1_BIT_STRING *)(**(code **)(local_68 + -0x78e8))(local_58);
    local_48._0_4_ = unaff_s5;
    algor2 = (X509_ALGOR *)(**(code **)(local_68 + -0x7dd8))(unaff_s5,s_a_sign_c_00679744,0xb0);
    if (algor1 == (X509_ALGOR *)0x0) {
      pcStack_f0 = s_a_sign_c_00679744;
      local_48._0_4_ = (ASN1_BIT_STRING *)0x0;
      pEStack_e0 = (EVP_PKEY *)&DAT_00000041;
      pAStack_e4 = (ASN1_BIT_STRING *)&DAT_00000080;
      local_70 = (X509_ALGOR *)0xb3;
      (**(code **)(local_68 + -0x6eac))(0xd);
      (**(code **)(local_68 + -0x7fac))(puStack_9c);
    }
    else {
      if ((EVP_PKEY *)algor2 == (EVP_PKEY *)0x0) {
        pcStack_f0 = s_a_sign_c_00679744;
        local_48._0_4_ = (ASN1_BIT_STRING *)0x0;
        pEStack_e0 = (EVP_PKEY *)&DAT_00000041;
        local_70 = (X509_ALGOR *)0xb3;
        (**(code **)(local_68 + -0x6eac))(0xd,0x80);
        (**(code **)(local_68 + -0x7fac))(puStack_9c);
      }
      else {
        local_4c = algor1;
        (*local_5c)(data,&local_4c);
        iVar3 = (**(code **)(local_68 + -0x7864))(puStack_9c,type,0);
        if ((iVar3 == 0) ||
           (iVar3 = (**(code **)(local_68 + -0x7860))(puStack_9c,algor1,pAStack_8c), iVar3 == 0)) {
LAB_00606b40:
          pcStack_f0 = s_a_sign_c_00679744;
          local_48._0_4_ = (ASN1_BIT_STRING *)0x0;
          pEStack_e0 = (EVP_PKEY *)&DAT_00000006;
          local_70 = (X509_ALGOR *)0xbe;
          (**(code **)(local_68 + -0x6eac))(0xd,0x80);
        }
        else {
          pEStack_e0 = (EVP_PKEY *)local_48;
          pcStack_f0 = (char *)local_58;
          iVar3 = (**(code **)(local_68 + -0x6e70))(puStack_9c,algor2);
          if (iVar3 == 0) goto LAB_00606b40;
          if (local_54->data != (uchar *)0x0) {
            (**(code **)(local_68 + -0x7f58))();
          }
          local_54->data = (uchar *)algor2;
          algor2 = (X509_ALGOR *)0x0;
          local_54->flags = local_54->flags & 0xfffffff0U | 8;
          local_54->length = (int)local_48._0_4_;
        }
        (**(code **)(local_68 + -0x7fac))(puStack_9c);
      }
      pAStack_e4 = pAStack_8c;
      (**(code **)(local_68 + -0x7d6c))(algor1);
      (**(code **)(local_68 + -0x7f58))(algor1);
    }
    if ((EVP_PKEY *)algor2 != (EVP_PKEY *)0x0) {
      pAStack_e4 = unaff_s5;
      (**(code **)(local_68 + -0x7d6c))(algor2);
      (**(code **)(local_68 + -0x7f58))(algor2);
    }
  }
  else {
    pAStack_8c = (ASN1_BIT_STRING *)0x0;
    if (algor2 != (X509_ALGOR *)0x0) {
      unaff_s4 = 5;
      do {
        unaff_s5 = (ASN1_BIT_STRING *)algor1;
        if (pAStack_8c != (ASN1_BIT_STRING *)0x0) {
          unaff_s5 = (ASN1_BIT_STRING *)algor2;
        }
        if (type->pkey_type == 0x71) {
          (**(code **)(local_68 + -0x7948))((ASN1_TYPE *)unaff_s5->type);
          unaff_s5->type = 0;
        }
        else if (((ASN1_TYPE *)unaff_s5->type == (ASN1_TYPE *)0x0) ||
                (((ASN1_TYPE *)unaff_s5->type)->type != 5)) {
          (**(code **)(local_68 + -0x7948))();
          pAVar1 = (ASN1_TYPE *)(**(code **)(local_68 + -0x6f14))();
          unaff_s5->type = (int)pAVar1;
          if (pAVar1 == (ASN1_TYPE *)0x0) goto LAB_00606e3c;
          pAVar1->type = 5;
        }
        (**(code **)(local_68 + -0x7ddc))((ASN1_OBJECT *)unaff_s5->length);
        pAVar2 = (ASN1_OBJECT *)(**(code **)(local_68 + -0x7ca0))(type->pkey_type);
        unaff_s5->length = (int)pAVar2;
        if (pAVar2 == (ASN1_OBJECT *)0x0) goto LAB_00606e8c;
        pcStack_f0 = (char *)0x680000;
        if (pAVar2->length == 0) goto LAB_00606e18;
        pAStack_8c = (ASN1_BIT_STRING *)((int)&pAStack_8c->length + 1);
      } while (pAStack_8c != (ASN1_BIT_STRING *)&SUB_00000002);
      goto LAB_00606a9c;
    }
    pcVar16 = *(code **)(local_68 + -0x7948);
    if (type->pkey_type == 0x71) {
      (*pcVar16)(algor1->parameter);
      algor1->parameter = (ASN1_TYPE *)0x0;
LAB_00606de0:
      pcVar16 = *(code **)(local_68 + -0x7ddc);
LAB_00606de4:
      (*pcVar16)(algor1->algorithm);
      pAVar2 = (ASN1_OBJECT *)(**(code **)(local_68 + -0x7ca0))(type->pkey_type);
      algor1->algorithm = pAVar2;
      if (pAVar2 == (ASN1_OBJECT *)0x0) {
LAB_00606e8c:
        pcVar16 = *(code **)(local_68 + -0x6eac);
        pEStack_e0 = (EVP_PKEY *)&DAT_000000a2;
        local_70 = (X509_ALGOR *)&DAT_000000a4;
      }
      else {
        if (pAVar2->length != 0) goto LAB_00606a9c;
LAB_00606e18:
        pcVar16 = *(code **)(local_68 + -0x6eac);
        pEStack_e0 = (EVP_PKEY *)0x9a;
        local_70 = (X509_ALGOR *)0xa9;
      }
      pcStack_f0 = s_a_sign_c_00679744;
      pAStack_e4 = (ASN1_BIT_STRING *)&DAT_00000080;
      (*pcVar16)(0xd);
    }
    else {
      if (algor1->parameter != (ASN1_TYPE *)0x0) {
        pcVar16 = *(code **)(local_68 + -0x7ddc);
        if (algor1->parameter->type != 5) {
          pcVar16 = *(code **)(local_68 + -0x7948);
          goto LAB_00606db4;
        }
        goto LAB_00606de4;
      }
LAB_00606db4:
      (*pcVar16)();
      pAVar1 = (ASN1_TYPE *)(**(code **)(local_68 + -0x6f14))();
      algor1->parameter = pAVar1;
      pcStack_f0 = (char *)signature;
      if (pAVar1 != (ASN1_TYPE *)0x0) {
        pAVar1->type = 5;
        goto LAB_00606de0;
      }
    }
LAB_00606e3c:
    (**(code **)(local_68 + -0x7fac))(puStack_9c);
  }
  if (local_2c == *(EVP_PKEY **)puStack_90) {
    return (int)local_48._0_4_;
  }
  pcStack_84 = ASN1_item_sign_ctx;
  pEStack_ec = local_2c;
  (**(code **)(local_68 + -0x5330))();
  pXStack_e8 = local_70;
  puStack_f8 = PTR___stack_chk_guard_006a9ae8;
  pEStack_a8 = type;
  pcStack_88 = data;
  pXStack_c0 = (X509_ALGOR *)&_gp;
  iStack_b8 = 0;
  XStack_b4.algorithm = (ASN1_OBJECT *)0x0;
  pAStack_ac = *(ASN1_ITEM **)PTR___stack_chk_guard_006a9ae8;
  pEStack_a4 = (EVP_PKEY *)algor2;
  pXStack_a0 = algor1;
  uStack_98 = unaff_s4;
  pAStack_94 = unaff_s5;
  pEStack_f4 = (EVP_PKEY *)(*(code *)PTR_EVP_MD_CTX_md_006a7500)(iStack_6c);
  pEStack_fc = (EVP_PKEY *)
               (*(code *)pXStack_c0[-0xb02].parameter)(*(undefined4 *)(iStack_6c + 0x10));
  if ((pEStack_f4 == (EVP_PKEY *)0x0) ||
     (algor2 = (X509_ALGOR *)pEStack_fc, pEStack_fc == (EVP_PKEY *)0x0)) {
    pAVar1 = pXStack_c0[-0xdd6].parameter;
    pXStack_154 = (X509_ALGOR *)0xd9;
    pEStack_c8 = (EVP_PKEY *)0xf7;
    pEStack_fc = (EVP_PKEY *)algor2;
LAB_006072c0:
    pcStack_14c = s_a_sign_c_00679744;
    pEStack_158 = (EVP_PKEY *)&DAT_000000dc;
    (*(code *)pAVar1)(0xd);
    pEVar5 = (EVP_PKEY *)0x0;
  }
  else {
    pEVar4 = pEStack_fc->ameth;
    pcStack_14c = (char *)pAStack_e4;
    if (*(code **)&pEVar4[0x68].field_0x0 == (code *)0x0) {
      pAVar1 = pXStack_c0[-0xf43].parameter;
      if (((uint)pEStack_f4->ameth & 4) == 0) {
LAB_00607194:
        XStack_b4.parameter = (ASN1_TYPE *)pEStack_f4->save_type;
      }
      else {
LAB_00607278:
        uVar8 = (*(code *)pAVar1)(pEStack_f4);
        iVar3 = (*(code *)pXStack_c0[-0xae5].parameter)
                          (&XStack_b4.parameter,uVar8,*(undefined4 *)&pEStack_fc->ameth->field_0x0);
        if (iVar3 == 0) {
LAB_00607330:
          pAVar1 = pXStack_c0[-0xdd6].parameter;
          pXStack_154 = (X509_ALGOR *)0xc6;
          pEStack_c8 = (EVP_PKEY *)0x114;
          goto LAB_006072c0;
        }
        pEVar4 = pEStack_fc->ameth;
      }
      uVar8 = 0xffffffff;
      if ((*(uint *)&pEVar4[8].field_0x0 & 4) != 0) {
        uVar8 = 5;
      }
      if (pAStack_e4 != (ASN1_BIT_STRING *)0x0) {
        uVar14 = (*(code *)pXStack_c0[-0xf94].algorithm)(XStack_b4.parameter);
        pcStack_14c = (char *)0x0;
        (*(code *)pXStack_c0[-0xc20].parameter)(pAStack_e4,uVar14,uVar8);
      }
      if (pEStack_e0 != (EVP_PKEY *)0x0) {
        uVar14 = (*(code *)pXStack_c0[-0xf94].algorithm)(XStack_b4.parameter);
        pcStack_14c = (char *)0x0;
        (*(code *)pXStack_c0[-0xc20].parameter)(pEStack_e0,uVar14,uVar8);
      }
LAB_00606fb4:
      pEStack_ec = (EVP_PKEY *)
                   (*(code *)pXStack_c0[-0xced].algorithm)(pXStack_e8,&iStack_b8,pEStack_ec);
      pXStack_e8 = (X509_ALGOR *)0x680000;
      pEStack_f4 = (EVP_PKEY *)(*(code *)pXStack_c0[-0xf1d].algorithm)(pEStack_fc);
      XStack_b4.algorithm = (ASN1_OBJECT *)pEStack_f4;
      pEStack_fc = (EVP_PKEY *)
                   (*(code *)pXStack_c0[-0xfbb].algorithm)(pEStack_f4,s_a_sign_c_00679744,0x128);
      if ((iStack_b8 == 0) || (pEStack_fc == (EVP_PKEY *)0x0)) {
        pcStack_14c = s_a_sign_c_00679744;
        XStack_b4.algorithm = (ASN1_OBJECT *)0x0;
        pXStack_154 = (X509_ALGOR *)&DAT_00000041;
        pEStack_158 = (EVP_PKEY *)&DAT_000000dc;
        pEStack_c8 = (EVP_PKEY *)0x12b;
        (*(code *)pXStack_c0[-0xdd6].parameter)(0xd);
        (*(code *)pXStack_c0[-0xff6].parameter)(iStack_6c);
        if (iStack_b8 != 0) goto LAB_00607154;
        goto LAB_00607174;
      }
      iVar3 = (*(code *)pXStack_c0[-0xf0c].algorithm)(iStack_6c,iStack_b8,pEStack_ec);
      if (iVar3 != 0) {
        pXStack_154 = &XStack_b4;
        pEStack_158 = pEStack_fc;
        iVar3 = (*(code *)pXStack_c0[-0xf22].algorithm)(iStack_6c);
        if (iVar3 != 0) {
          if (*(uchar **)((int)pcStack_f0 + 8) != (uchar *)0x0) {
            (*(code *)pXStack_c0[-0xfeb].algorithm)();
          }
          *(EVP_PKEY **)((int)pcStack_f0 + 8) = pEStack_fc;
          *(EVP_PKEY_ASN1_METHOD **)((int)pcStack_f0 + 0xc) =
               (EVP_PKEY_ASN1_METHOD *)
               ((uint)*(EVP_PKEY_ASN1_METHOD **)((int)pcStack_f0 + 0xc) & 0xfffffff0 | 8);
          *(ASN1_OBJECT **)pcStack_f0 = XStack_b4.algorithm;
          goto LAB_00607138;
        }
      }
      pcStack_14c = s_a_sign_c_00679744;
      XStack_b4.algorithm = (ASN1_OBJECT *)0x0;
      pXStack_154 = (X509_ALGOR *)&DAT_00000006;
      pEStack_c8 = (EVP_PKEY *)0x132;
      (*(code *)pXStack_c0[-0xdd6].parameter)(0xd,0xdc);
      (*(code *)pXStack_c0[-0xff6].parameter)(iStack_6c);
      if (iStack_b8 != 0) goto LAB_00607154;
      pAVar1 = pXStack_c0[-0xfae].parameter;
    }
    else {
      pEStack_158 = pEStack_ec;
      pXStack_154 = pXStack_e8;
      pEStack_c8 = pEStack_e0;
      pEStack_c4 = (EVP_PKEY *)pcStack_f0;
      iVar3 = (**(code **)&pEVar4[0x68].field_0x0)(iStack_6c);
      if (iVar3 == 1) {
        XStack_b4.algorithm = *(ASN1_OBJECT **)pcStack_f0;
        pEStack_f4 = (EVP_PKEY *)0x0;
        pEStack_ec = (EVP_PKEY *)0x0;
LAB_00607138:
        (*(code *)pXStack_c0[-0xff6].parameter)(iStack_6c);
        pEVar5 = (EVP_PKEY *)XStack_b4.algorithm;
        if (iStack_b8 == 0) goto LAB_006070ec;
        pEStack_fc = (EVP_PKEY *)0x0;
      }
      else {
        if (0 < iVar3) {
          if (iVar3 == 2) {
            pEVar4 = pEStack_fc->ameth;
            if (((uint)pEStack_f4->ameth & 4) != 0) {
              if (pEVar4 != (EVP_PKEY_ASN1_METHOD *)0x0) {
                pAVar1 = pXStack_c0[-0xf43].parameter;
                pcStack_14c = (char *)(ASN1_BIT_STRING *)0x680000;
                goto LAB_00607278;
              }
              goto LAB_00607330;
            }
            goto LAB_00607194;
          }
          goto LAB_00606fb4;
        }
        pXStack_154 = (X509_ALGOR *)&DAT_00000006;
        pcStack_14c = s_a_sign_c_00679744;
        pEStack_c8 = (EVP_PKEY *)0x107;
        pEStack_158 = (EVP_PKEY *)&DAT_000000dc;
        (*(code *)pXStack_c0[-0xdd6].parameter)(0xd);
        (*(code *)pXStack_c0[-0xff6].parameter)(iStack_6c);
        pEVar5 = (EVP_PKEY *)XStack_b4.algorithm;
        if (iStack_b8 == 0) goto LAB_006070ec;
        pEStack_f4 = (EVP_PKEY *)0x0;
        pEStack_ec = (EVP_PKEY *)0x0;
        pEStack_fc = (EVP_PKEY *)0x0;
      }
LAB_00607154:
      pEStack_158 = pEStack_ec;
      (*(code *)pXStack_c0[-0xfae].parameter)();
      (*(code *)pXStack_c0[-0xfeb].algorithm)(iStack_b8);
LAB_00607174:
      pAVar1 = pXStack_c0[-0xfae].parameter;
      pEVar5 = (EVP_PKEY *)XStack_b4.algorithm;
      if (pEStack_fc == (EVP_PKEY *)0x0) goto LAB_006070ec;
    }
    pEStack_158 = pEStack_f4;
    (*(code *)pAVar1)(pEStack_fc);
    (*(code *)pXStack_c0[-0xfeb].algorithm)(pEStack_fc);
    pEVar5 = (EVP_PKEY *)XStack_b4.algorithm;
  }
LAB_006070ec:
  if (pAStack_ac == *(ASN1_ITEM **)puStack_f8) {
    return (int)pEVar5;
  }
  pcStack_dc = ASN1_item_sign;
  pAStack_15c = pAStack_ac;
  (*(code *)pXStack_c0[-0xa66].algorithm)();
  pXStack_1e8 = pXStack_c0;
  pEStack_148 = pEStack_c4;
  pEStack_150 = pEStack_c8;
  puStack_160 = PTR___stack_chk_guard_006a9ae8;
  iStack_100 = iStack_6c;
  pEStack_1a4 = &EStack_11c;
  pcStack_104 = *(code **)PTR___stack_chk_guard_006a9ae8;
  (*(code *)PTR_EVP_MD_CTX_init_006a6e1c)(pEStack_1a4);
  pAStack_1dc = (ASN1_BIT_STRING *)0x0;
  pEStack_248 = (EVP_PKEY *)0x0;
  pEStack_1d8 = pEStack_148;
  iStack_164 = (*(code *)PTR_EVP_DigestSignInit_006a6e20)(pEStack_1a4);
  if (iStack_164 == 0) {
    (*(code *)PTR_EVP_MD_CTX_cleanup_006a6e34)(pEStack_1a4);
  }
  else {
    pEStack_248 = pEStack_158;
    pXStack_1e8 = pXStack_154;
    pAStack_1dc = (ASN1_BIT_STRING *)pcStack_14c;
    pEStack_1d8 = pEStack_150;
    iStack_164 = ASN1_item_sign_ctx(pAStack_15c,(X509_ALGOR *)pEStack_158,pXStack_154,
                                    (ASN1_BIT_STRING *)pcStack_14c,pEStack_150,pEStack_1a4);
  }
  if (pcStack_104 == *(code **)puStack_160) {
    return iStack_164;
  }
  uStack_144 = 0x607474;
  pcStack_198 = pcStack_104;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puStack_1a0 = PTR___stack_chk_guard_006a9ae8;
  puStack_178 = &_gp;
  pEStack_16c = *(EVP_PKEY **)PTR___stack_chk_guard_006a9ae8;
  pEStack_168 = pEStack_1a4;
  pcStack_19c = (char *)(*pcStack_198)(pXStack_1e8,0);
  pEVar6 = (EVP_MD_CTX *)
           (**(code **)(puStack_178 + -0x7dd8))(pcStack_19c,s_a_digest_c_00679750,0x52);
  if (pEVar6 == (EVP_MD_CTX *)0x0) {
    pcStack_1f0 = s_a_digest_c_00679750;
    pAVar13 = (ASN1_BIT_STRING *)&DAT_00000041;
    pcStack_1f4 = (char *)0xb8;
    pEStack_180 = (EVP_PKEY *)0x53;
    (**(code **)(puStack_178 + -0x6eac))(0xd,0xb8,0x41);
    iVar3 = 0;
  }
  else {
    pEStack_170 = pEVar6;
    (*pcStack_198)(pXStack_1e8,&pEStack_170);
    uStack_17c = 0;
    pcStack_1f4 = pcStack_19c;
    pAVar13 = pAStack_1dc;
    pcStack_1f0 = (char *)pEStack_1d8;
    pEStack_180 = pEStack_248;
    iVar3 = (**(code **)(puStack_178 + -0x73cc))(pEVar6,pcStack_19c,pAStack_1dc);
    pEStack_1a4 = pEVar6;
    if (iVar3 != 0) {
      (**(code **)(puStack_178 + -0x7f58))(pEVar6);
      iVar3 = 1;
    }
  }
  if (pEStack_16c == *(EVP_PKEY **)puStack_1a0) {
    return iVar3;
  }
  pcStack_194 = ASN1_item_digest;
  pEStack_24c = pEStack_16c;
  (**(code **)(puStack_178 + -0x5330))();
  pEStack_1ec = pEStack_180;
  puStack_1f8 = PTR___stack_chk_guard_006a9ae8;
  piVar11 = &iStack_1b0;
  puStack_1b8 = &_gp;
  iStack_1b0 = 0;
  pcStack_1ac = *(code **)PTR___stack_chk_guard_006a9ae8;
  pEStack_250 = (EVP_PKEY *)pcStack_1f0;
  piVar7 = (int *)(*(code *)PTR_ASN1_item_i2d_006a8678)(pAVar13);
  if (iStack_1b0 == 0) {
LAB_0060766c:
    piVar7 = piVar11;
    iVar3 = 0;
  }
  else {
    uStack_1bc = 0;
    pEStack_24c = (EVP_PKEY *)pcStack_1f0;
    pEStack_250 = pEStack_1ec;
    pcStack_1c0 = pcStack_1f4;
    iVar3 = (**(code **)(puStack_1b8 + -0x73cc))();
    piVar11 = piVar7;
    if (iVar3 == 0) goto LAB_0060766c;
    (**(code **)(puStack_1b8 + -0x7f58))(iStack_1b0);
    iVar3 = 1;
  }
  if (pcStack_1ac == *(code **)puStack_1f8) {
    return iVar3;
  }
  uStack_1d4 = 0x6076bc;
  pcStack_254 = pcStack_1ac;
  (**(code **)(puStack_1b8 + -0x5330))();
  puStack_25c = PTR___stack_chk_guard_006a9ae8;
  puStack_260 = auStack_214;
  pcStack_21c = pcStack_1c0;
  uStack_1e4 = 0x680000;
  puStack_228 = &_gp;
  piStack_1fc = *(int **)PTR___stack_chk_guard_006a9ae8;
  pEStack_1e0 = pEStack_248;
  (*(code *)PTR_EVP_MD_CTX_init_006a6e1c)(puStack_260);
  uVar8 = (**(code **)(puStack_228 + -0x7cb4))(*piVar7);
  uVar8 = (**(code **)(puStack_228 + -0x7d44))(uVar8);
  iVar3 = (**(code **)(puStack_228 + -0x7eb4))(uVar8);
  if (iVar3 == 0) {
    pcVar16 = *(code **)(puStack_228 + -0x6eac);
    pAVar2 = (ASN1_OBJECT *)0xa1;
    iStack_230 = 0x59;
LAB_006078ec:
    pcVar15 = "a_verify.c";
    puVar12 = (undefined4 *)&DAT_00000089;
    iStack_258 = -1;
    (*pcVar16)(0xd,0x89,pAVar2,"a_verify.c");
  }
  else {
    if (((ASN1_TYPE *)pEStack_24c->save_type == (ASN1_TYPE *)0x3) &&
       (((uint)pEStack_24c->ameth & 7) != 0)) {
      pcVar16 = *(code **)(puStack_228 + -0x6eac);
      pAVar2 = (ASN1_OBJECT *)&DAT_000000dc;
      iStack_230 = 0x5e;
      goto LAB_006078ec;
    }
    pEStack_248 = (EVP_PKEY *)(*pcStack_254)(pEStack_250,0);
    iVar9 = (**(code **)(puStack_228 + -0x7dd8))(pEStack_248,"a_verify.c",99);
    if (iVar9 == 0) {
      pcVar15 = "a_verify.c";
      pAVar2 = (ASN1_OBJECT *)&DAT_00000041;
      puVar12 = (undefined4 *)&DAT_00000089;
      iStack_230 = 0x65;
      iStack_258 = -1;
      (**(code **)(puStack_228 + -0x6eac))(0xd,0x89,0x41,"a_verify.c");
    }
    else {
      iStack_218 = iVar9;
      (*pcStack_254)(pEStack_250,&iStack_218);
      iVar3 = (**(code **)(puStack_228 + -0x7864))(puStack_260,iVar3,0);
      if ((iVar3 == 0) ||
         (iVar3 = (**(code **)(puStack_228 + -0x7860))(puStack_260,iVar9,pEStack_248), iVar3 == 0))
      {
        pcVar16 = *(code **)(puStack_228 + -0x6eac);
        iStack_230 = 0x6d;
      }
      else {
        (**(code **)(puStack_228 + -0x7d6c))(iVar9,pEStack_248);
        (**(code **)(puStack_228 + -0x7f58))(iVar9);
        pAVar2 = (ASN1_OBJECT *)pEStack_24c->type;
        puVar12 = (undefined4 *)pEStack_24c->references;
        pcVar15 = pcStack_21c;
        iVar3 = (**(code **)(puStack_228 + -0x6e04))(puStack_260,puVar12,pAVar2,pcStack_21c);
        if (0 < iVar3) {
          iStack_258 = 1;
          goto LAB_0060782c;
        }
        pcVar16 = *(code **)(puStack_228 + -0x6eac);
        iStack_230 = 0x77;
      }
      pcVar15 = "a_verify.c";
      pAVar2 = (ASN1_OBJECT *)&DAT_00000006;
      puVar12 = (undefined4 *)&DAT_00000089;
      iStack_258 = 0;
      (*pcVar16)(0xd,0x89,6,"a_verify.c");
    }
  }
LAB_0060782c:
  (**(code **)(puStack_228 + -0x7fac))(puStack_260);
  if (piStack_1fc == *(int **)puStack_25c) {
    return iStack_258;
  }
  pcStack_244 = ASN1_item_verify;
  piVar11 = piStack_1fc;
  (**(code **)(puStack_228 + -0x5330))();
  iVar3 = iStack_230;
  puVar17 = PTR___stack_chk_guard_006a9ae8;
  iStack_288 = 0;
  iStack_264 = *(int *)PTR___stack_chk_guard_006a9ae8;
  if (iStack_230 == 0) {
    uVar14 = 0x43;
    uVar8 = 0x92;
  }
  else {
    if ((pAVar2->ln != (char **)0x3) || ((pAVar2->length & 7U) == 0)) {
      (*(code *)PTR_EVP_MD_CTX_init_006a6e1c)(auStack_27c);
      uVar8 = (*(code *)PTR_OBJ_obj2nid_006a712c)(*puVar12);
      iVar9 = (*(code *)PTR_OBJ_find_sigid_algs_006a834c)(uVar8,&iStack_284,&uStack_280);
      if (iVar9 == 0) {
        uVar14 = 199;
        uVar8 = 0x9f;
LAB_00607b58:
        piVar7 = (int *)0xc5;
        iVar3 = -1;
        (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0xc5,uVar14,"a_verify.c",uVar8);
      }
      else {
        if (iStack_284 != 0) {
          uVar8 = (*(code *)PTR_OBJ_nid2sn_006a709c)();
          iVar9 = (*(code *)PTR_EVP_get_digestbyname_006a6f2c)(uVar8);
          if (iVar9 == 0) {
            uVar14 = 0xa1;
            uVar8 = 0xb6;
          }
          else {
            iVar10 = (*(code *)PTR_EVP_PKEY_type_006a97e0)(uStack_280);
            if (iVar10 == **(int **)(iVar3 + 0xc)) {
              iVar3 = (*(code *)PTR_EVP_DigestVerifyInit_006a74f4)(auStack_27c,0,iVar9,0,iVar3);
              if (iVar3 != 0) goto LAB_00607b88;
              uVar8 = 0xc1;
              goto LAB_00607bd8;
            }
            uVar14 = 200;
            uVar8 = 0xbc;
          }
          goto LAB_00607b58;
        }
        if ((*(int *)(iVar3 + 0xc) == 0) ||
           (pcVar16 = *(code **)(*(int *)(iVar3 + 0xc) + 100), pcVar16 == (code *)0x0)) {
          uVar14 = 199;
          uVar8 = 0xa5;
          goto LAB_00607b58;
        }
        piVar7 = piVar11;
        iVar3 = (*pcVar16)(auStack_27c,piVar11,pcVar15,puVar12,pAVar2,iVar3);
        if (iVar3 == 2) {
LAB_00607b88:
          uVar8 = (*(code *)PTR_ASN1_item_i2d_006a8678)(pcVar15,&iStack_288,piVar11);
          if (iStack_288 == 0) {
            uVar14 = 0x41;
            uVar8 = 0xcb;
            goto LAB_00607b58;
          }
          iVar3 = (*(code *)PTR_EVP_DigestUpdate_006a7580)(auStack_27c,iStack_288,uVar8);
          if (iVar3 == 0) {
            uVar8 = 0xd0;
          }
          else {
            (*(code *)PTR_OPENSSL_cleanse_006a7074)(iStack_288,uVar8);
            (*(code *)PTR_CRYPTO_free_006a6e88)(iStack_288);
            piVar7 = (int *)pAVar2->nid;
            iVar3 = (*(code *)PTR_EVP_DigestVerifyFinal_006a74cc)(auStack_27c,piVar7,pAVar2->sn);
            if (0 < iVar3) {
              iVar3 = 1;
              goto LAB_00607a64;
            }
            uVar8 = 0xda;
          }
LAB_00607bd8:
          piVar7 = (int *)0xc5;
          iVar3 = 0;
          (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0xc5,6,"a_verify.c",uVar8);
        }
      }
LAB_00607a64:
      (*(code *)PTR_EVP_MD_CTX_cleanup_006a6e34)(auStack_27c);
      goto LAB_00607a78;
    }
    uVar14 = 0xdc;
    uVar8 = 0x97;
  }
  piVar7 = (int *)0xc5;
  (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0xc5,uVar14,"a_verify.c",uVar8);
  iVar3 = -1;
LAB_00607a78:
  if (iStack_264 != *(int *)puVar17) {
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
    *piVar7 = *piVar7 + 1;
    return 1;
  }
  return iVar3;
}

