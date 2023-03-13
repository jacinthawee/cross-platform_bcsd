
/* WARNING: Could not reconcile some variable overlaps */

ASN1_TYPE * parse_tagging(ASN1_TYPE *param_1,ASN1_TYPE *param_2,int *param_3,undefined4 *param_4)

{
  char cVar1;
  undefined *puVar2;
  int iVar3;
  ASN1_TYPE *pAVar4;
  int iVar5;
  int iVar6;
  ASN1_STRING *pAVar7;
  uint uVar8;
  uchar *puVar9;
  ulong uVar10;
  undefined4 uVar11;
  ASN1_TIME *t;
  char *pcVar12;
  int *piVar13;
  undefined4 uVar14;
  char *pcVar15;
  ASN1_TYPE *unaff_s0;
  ASN1_TYPE *unaff_s2;
  int *unaff_s3;
  undefined4 *unaff_s4;
  code *pcVar16;
  uchar *puStack_240;
  uchar *puStack_23c;
  uchar *puStack_238;
  uchar *puStack_234;
  int iStack_230;
  int iStack_22c;
  uchar *puStack_228;
  undefined4 uStack_224;
  char *pcStack_220;
  int aiStack_21c [4];
  char *pcStack_20c;
  ASN1_TYPE aAStack_208 [50];
  int iStack_78;
  int iStack_74;
  ASN1_TYPE *pAStack_6c;
  undefined *puStack_68;
  ASN1_TYPE *pAStack_64;
  int *piStack_60;
  undefined4 *puStack_5c;
  undefined8 local_24;
  int local_1c;
  
  puStack_68 = PTR___stack_chk_guard_006a9ae8;
  local_1c = *(int *)PTR___stack_chk_guard_006a9ae8;
  pcVar12 = (char *)param_2;
  piVar13 = param_3;
  pcVar15 = (char *)param_4;
  pAStack_64 = unaff_s2;
  piStack_60 = unaff_s3;
  puStack_5c = unaff_s4;
  if (param_1 == (ASN1_TYPE *)0x0) {
LAB_00565190:
    param_1 = unaff_s0;
    pAVar4 = (ASN1_TYPE *)0x0;
  }
  else {
    pcVar12 = (char *)&local_24;
    piVar13 = (int *)&DAT_0000000a;
    iVar3 = (*(code *)PTR_strtoul_006a9a2c)();
    pAStack_64 = param_2;
    piStack_60 = param_3;
    puStack_5c = param_4;
    if (local_24._0_4_ == (char *)0x0) {
      if (-1 < iVar3) {
        *param_3 = iVar3;
        goto LAB_005651a4;
      }
LAB_00565258:
      piVar13 = (int *)0xbb;
      pcVar15 = "asn1_gen.c";
      pcVar12 = (char *)0xb6;
      (*(code *)PTR_ERR_put_error_006a7f34)(0xd);
      pAVar4 = (ASN1_TYPE *)0x0;
    }
    else {
      if ((*local_24._0_4_ != '\0') &&
         (unaff_s0 = param_1, (char *)((int)&param_2->type + (int)&param_1->type) < local_24._0_4_))
      goto LAB_00565190;
      param_1 = (ASN1_TYPE *)(local_24._0_4_ + -(int)param_1);
      if (iVar3 < 0) goto LAB_00565258;
      *param_3 = iVar3;
      if (param_2 != param_1) {
        cVar1 = *local_24._0_4_;
        if (cVar1 != 'C') {
          if (cVar1 < 'D') {
            if (cVar1 == 'A') {
              pAVar4 = (ASN1_TYPE *)0x1;
              *param_4 = 0x40;
            }
            else {
LAB_005651f8:
              local_24._5_1_ = 0;
              pcVar15 = "asn1_gen.c";
              local_24._4_1_ = cVar1;
              (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0xb6,0xba);
              piVar13 = (int *)((int)&local_24 + 4);
              pcVar12 = "Char=";
              (*(code *)PTR_ERR_add_error_data_006a813c)(2);
              pAVar4 = (ASN1_TYPE *)0x0;
            }
          }
          else if (cVar1 == 'P') {
            pAVar4 = (ASN1_TYPE *)0x1;
            *param_4 = 0xc0;
          }
          else {
            if (cVar1 != 'U') goto LAB_005651f8;
            *param_4 = 0;
            pAVar4 = (ASN1_TYPE *)0x1;
          }
          goto LAB_005651b0;
        }
      }
LAB_005651a4:
      pAVar4 = (ASN1_TYPE *)0x1;
      *param_4 = 0x80;
    }
  }
LAB_005651b0:
  if (local_1c == *(int *)puStack_68) {
    return pAVar4;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  aiStack_21c[0] = -1;
  aiStack_21c[1] = -1;
  aiStack_21c[3] = 1;
  puStack_240 = (uchar *)0x0;
  iStack_78 = 0;
  iStack_74 = *(int *)PTR___stack_chk_guard_006a9ae8;
  pAStack_6c = param_1;
  iVar5 = (*(code *)PTR_CONF_parse_list_006a87f8)();
  iVar3 = aiStack_21c[3];
  if (iVar5 != 0) {
    pAVar4 = (ASN1_TYPE *)0x0;
    *(undefined4 *)pcVar15 = 0xc2;
    goto LAB_005655dc;
  }
  if (aiStack_21c[2] - 0x10U < 2) {
    if ((ASN1_TYPE *)pcVar12 == (ASN1_TYPE *)0x0) {
      pAVar4 = (ASN1_TYPE *)0x0;
      *(undefined4 *)pcVar15 = 0xc0;
      goto LAB_005655dc;
    }
    if (0x31 < (int)piVar13) {
      pAVar4 = (ASN1_TYPE *)0x0;
      *(undefined4 *)pcVar15 = 0xb5;
      goto LAB_005655dc;
    }
    puStack_228 = (uchar *)0x0;
    iVar3 = (*(code *)PTR_sk_new_null_006a6fa4)();
    if (iVar3 == 0) {
      pAVar4 = (ASN1_TYPE *)0x0;
      param_1 = pAVar4;
      if (puStack_228 == (uchar *)0x0) goto LAB_005655d8;
      iVar5 = 0;
LAB_005655a0:
      (*(code *)PTR_CRYPTO_free_006a6e88)();
      if (iVar3 != 0) {
        (*(code *)PTR_sk_pop_free_006a7058)(iVar3,PTR_ASN1_TYPE_free_006a7498);
      }
    }
    else {
      if (pcStack_20c == (char *)0x0) {
        iVar5 = 0;
LAB_00565438:
        pcVar16 = (code *)PTR_i2d_ASN1_SET_ANY_006a8dcc;
        if (aiStack_21c[2] != 0x11) {
          pcVar16 = (code *)PTR_i2d_ASN1_SEQUENCE_ANY_006a8dd0;
        }
        iVar6 = (*pcVar16)(iVar3,&puStack_228);
        if (iVar6 < 0) {
LAB_00565590:
          pAVar4 = (ASN1_TYPE *)0x0;
          goto LAB_00565594;
        }
        pAVar4 = ASN1_TYPE_new();
        if (pAVar4 == (ASN1_TYPE *)0x0) goto LAB_00565594;
        pAVar7 = ASN1_STRING_type_new(aiStack_21c[2]);
        (pAVar4->value).asn1_string = pAVar7;
        if (pAVar7 == (ASN1_STRING *)0x0) goto LAB_00565594;
        pAVar4->type = aiStack_21c[2];
        pAVar7->length = iVar6;
        pAVar7->data = puStack_228;
        puStack_228 = (uchar *)0x0;
      }
      else {
        pAVar4 = (ASN1_TYPE *)0x0;
        iVar5 = (*(code *)PTR_X509V3_get_section_006a8dc8)(pcVar12,pcStack_20c);
        if (iVar5 != 0) {
          for (; iVar6 = (*(code *)PTR_sk_num_006a6e2c)(iVar5), (int)pAVar4 < iVar6;
              pAVar4 = (ASN1_TYPE *)((int)&pAVar4->type + 1)) {
            iVar6 = (*(code *)PTR_sk_value_006a6e24)(iVar5,pAVar4);
            iVar6 = generate_v3(*(undefined4 *)(iVar6 + 8),pcVar12,(undefined *)((int)piVar13 + 1),
                                pcVar15);
            if ((iVar6 == 0) || (iVar6 = (*(code *)PTR_sk_push_006a6fa8)(iVar3,iVar6), iVar6 == 0))
            goto LAB_00565590;
          }
          goto LAB_00565438;
        }
LAB_00565594:
        if (puStack_228 != (uchar *)0x0) goto LAB_005655a0;
      }
      (*(code *)PTR_sk_pop_free_006a7058)(iVar3,PTR_ASN1_TYPE_free_006a7498);
    }
    if (iVar5 != 0) {
      (*(code *)PTR_X509V3_section_free_006a8dd4)(pcVar12,iVar5);
    }
  }
  else {
    pAVar4 = ASN1_TYPE_new();
    if (pAVar4 == (ASN1_TYPE *)0x0) {
      (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0xb3,0x41,"asn1_gen.c",0x289);
      param_1 = pAVar4;
      goto LAB_005655d8;
    }
    if (pcStack_20c == (char *)0x0) {
      pcStack_20c = "";
    }
    switch(aiStack_21c[2]) {
    default:
      uVar14 = 0xc4;
      uVar11 = 0x31c;
LAB_005659e4:
      (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0xb3,uVar14,"asn1_gen.c",uVar11);
      (*(code *)PTR_ERR_add_error_data_006a813c)(2,"string=",pcStack_20c);
      while( true ) {
        ASN1_TYPE_free(pAVar4);
        param_1 = pAVar4;
LAB_005655d8:
        pAVar4 = (ASN1_TYPE *)0x0;
LAB_005655dc:
        if (iStack_74 == *(int *)puVar2) break;
        (*(code *)PTR___stack_chk_fail_006a9ab0)();
        pAVar4 = param_1;
LAB_00565c28:
        uVar14 = 0x41;
        uVar11 = 0x2f4;
LAB_00565a74:
        (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0xb3,uVar14,"asn1_gen.c",uVar11);
      }
      return pAVar4;
    case 1:
      if (iVar3 != 1) {
        uVar14 = 0xbe;
        uVar11 = 0x29b;
        goto LAB_00565a74;
      }
      uStack_224 = 0;
      puStack_228 = (uchar *)0x0;
      pcStack_220 = pcStack_20c;
      iVar3 = (*(code *)PTR_X509V3_get_value_bool_006a8dd8)(&puStack_228,&pAVar4->value);
      if (iVar3 == 0) {
        uVar14 = 0xb0;
        uVar11 = 0x2a2;
        goto LAB_005659e4;
      }
      break;
    case 2:
    case 10:
      if (iVar3 != 1) {
        uVar14 = 0xb9;
        uVar11 = 0x2aa;
        goto LAB_00565a74;
      }
      pcVar12 = (char *)(*(code *)PTR_s2i_ASN1_INTEGER_006a6fb4)(0,pcStack_20c);
      (pAVar4->value).ptr = pcVar12;
      if (pcVar12 == (char *)0x0) {
        uVar14 = 0xb4;
        uVar11 = 0x2ae;
        goto LAB_005659e4;
      }
      break;
    case 3:
    case 4:
      pAVar7 = ASN1_STRING_new();
      (pAVar4->value).asn1_string = pAVar7;
      if (pAVar7 == (ASN1_STRING *)0x0) goto LAB_00565c28;
      if (iVar3 == 3) {
        puVar9 = (uchar *)(*(code *)PTR_string_to_hex_006a738c)(pcStack_20c,&iStack_22c);
        if (puVar9 == (uchar *)0x0) {
          uVar14 = 0xb2;
          uVar11 = 0x2fb;
          goto LAB_005659e4;
        }
        pAVar7 = (pAVar4->value).asn1_string;
        pAVar7->data = puVar9;
        pAVar7->length = iStack_22c;
        pAVar7->type = aiStack_21c[2];
      }
      else {
        if (iVar3 != 1) {
          if ((iVar3 != 4) || (aiStack_21c[2] != 3)) {
            uVar14 = 0xaf;
            uVar11 = 0x30f;
            goto LAB_00565a74;
          }
          iVar3 = (*(code *)PTR_CONF_parse_list_006a87f8)(pcStack_20c,0x2c,1,bitstr_cb,pAVar7);
          if (iVar3 == 0) {
            uVar14 = 0xbc;
            uVar11 = 0x309;
            goto LAB_005659e4;
          }
          break;
        }
        ASN1_STRING_set(pAVar7,pcStack_20c,-1);
      }
      if (aiStack_21c[2] == 3) {
        ((pAVar4->value).asn1_string)->flags =
             ((pAVar4->value).asn1_string)->flags & 0xfffffff0U | 8;
        pAVar4->type = 3;
        goto LAB_005654d0;
      }
      break;
    case 5:
      if (*pcStack_20c != '\0') {
        uVar14 = 0xb6;
        uVar11 = 0x294;
        goto LAB_00565a74;
      }
      break;
    case 6:
      if (iVar3 != 1) {
        uVar14 = 0xbf;
        uVar11 = 0x2b5;
        goto LAB_00565a74;
      }
      pcVar12 = (char *)(*(code *)PTR_OBJ_txt2obj_006a7000)(pcStack_20c,0);
      (pAVar4->value).ptr = pcVar12;
      if (pcVar12 == (char *)0x0) {
        uVar14 = 0xb7;
        uVar11 = 0x2b9;
        goto LAB_005659e4;
      }
      break;
    case 0xc:
    case 0x12:
    case 0x13:
    case 0x14:
    case 0x16:
    case 0x1a:
    case 0x1b:
    case 0x1c:
    case 0x1e:
      if (iVar3 == 1) {
        uVar11 = 0x1001;
      }
      else {
        uVar11 = 0x1000;
        if (iVar3 != 2) {
          uVar14 = 0xb1;
          uVar11 = 0x2e3;
          goto LAB_00565a74;
        }
      }
      uVar10 = ASN1_tag2bit(aiStack_21c[2]);
      iVar3 = (*(code *)PTR_ASN1_mbstring_copy_006a8cd4)
                        (&pAVar4->value,pcStack_20c,0xffffffff,uVar11,uVar10);
      if (iVar3 < 1) {
        uVar14 = 0x41;
        uVar11 = 0x2e9;
        goto LAB_005659e4;
      }
      break;
    case 0x17:
    case 0x18:
      if (iVar3 != 1) {
        uVar14 = 0xc1;
        uVar11 = 0x2c1;
        goto LAB_00565a74;
      }
      pAVar7 = ASN1_STRING_new();
      (pAVar4->value).asn1_string = pAVar7;
      if (pAVar7 == (ASN1_STRING *)0x0) {
        uVar14 = 0x41;
        uVar11 = 0x2c5;
        goto LAB_005659e4;
      }
      iVar3 = ASN1_STRING_set(pAVar7,pcStack_20c,-1);
      if (iVar3 == 0) {
        uVar14 = 0x41;
        uVar11 = 0x2c9;
        goto LAB_005659e4;
      }
      t = (pAVar4->value).asn1_string;
      t->type = aiStack_21c[2];
      iVar3 = ASN1_TIME_check(t);
      if (iVar3 == 0) {
        uVar14 = 0xb8;
        uVar11 = 0x2ce;
        goto LAB_005659e4;
      }
    }
    pAVar4->type = aiStack_21c[2];
  }
LAB_005654d0:
  param_1 = pAVar4;
  if (pAVar4 == (ASN1_TYPE *)0x0) goto LAB_005655d8;
  if ((aiStack_21c[0] == -1) && (iStack_78 == 0)) goto LAB_005655dc;
  iVar3 = i2d_ASN1_TYPE(pAVar4,&puStack_240);
  ASN1_TYPE_free(pAVar4);
  puStack_23c = puStack_240;
  if (aiStack_21c[0] == -1) {
    uVar8 = 0;
    iVar5 = iVar3;
  }
  else {
    uVar8 = ASN1_get_object(&puStack_23c,&iStack_230,&iStack_22c,(int *)&puStack_228,iVar3);
    if ((uVar8 & 0x80) != 0) goto LAB_005655cc;
    iVar5 = iVar3 - ((int)puStack_23c - (int)puStack_240);
    if ((uVar8 & 1) == 0) {
      uVar8 = uVar8 & 0x20;
    }
    else {
      iStack_230 = 0;
      uVar8 = 2;
    }
    iVar3 = ASN1_object_size(0,iStack_230,aiStack_21c[0]);
  }
  pAVar4 = aAStack_208;
  if (0 < iStack_78) {
    iVar6 = 0;
    piVar13 = (int *)((int)pAVar4 + iStack_78 * 0x14 + -0x14);
    do {
      iVar6 = iVar6 + 1;
      piVar13[4] = iVar3 + piVar13[3];
      iVar3 = ASN1_object_size(0,iVar3 + piVar13[3],*piVar13);
      piVar13 = piVar13 + -5;
    } while (iVar6 < iStack_78);
  }
  puVar9 = (uchar *)(*(code *)PTR_CRYPTO_malloc_006a7008)(iVar3,"asn1_gen.c",0xf5);
  if (puVar9 != (uchar *)0x0) {
    puStack_238 = puVar9;
    if (0 < iStack_78) {
      iVar6 = 0;
      do {
        ASN1_put_object(&puStack_238,pAVar4[1].type,pAVar4[2].type,pAVar4->type,
                        (pAVar4->value).boolean);
        if (pAVar4[1].value.ptr != (char *)0x0) {
          *puStack_238 = '\0';
          puStack_238 = puStack_238 + 1;
        }
        iVar6 = iVar6 + 1;
        pAVar4 = (ASN1_TYPE *)&pAVar4[2].value;
      } while (iVar6 < iStack_78);
    }
    if (aiStack_21c[0] != -1) {
      if ((aiStack_21c[1] == 0) && (aiStack_21c[0] - 0x10U < 2)) {
        uVar8 = 0x20;
      }
      ASN1_put_object(&puStack_238,uVar8,iStack_230,aiStack_21c[0],aiStack_21c[1]);
    }
    (*(code *)PTR_memcpy_006a9aec)(puStack_238,puStack_23c,iVar5);
    puStack_234 = puVar9;
    pAVar4 = d2i_ASN1_TYPE((ASN1_TYPE **)0x0,&puStack_234,iVar3);
    if (puStack_240 != (uchar *)0x0) {
      (*(code *)PTR_CRYPTO_free_006a6e88)();
    }
    (*(code *)PTR_CRYPTO_free_006a6e88)(puVar9);
    param_1 = pAVar4;
    goto LAB_005655dc;
  }
LAB_005655cc:
  param_1 = pAVar4;
  if (puStack_240 == (uchar *)0x0) goto LAB_005655d8;
  (*(code *)PTR_CRYPTO_free_006a6e88)();
  goto LAB_005655d8;
}

