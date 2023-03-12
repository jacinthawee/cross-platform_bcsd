
ASN1_TYPE * generate_v3(undefined4 param_1,int param_2,int param_3,undefined4 *param_4)

{
  undefined *puVar1;
  int iVar2;
  ASN1_TYPE *a;
  int iVar3;
  int iVar4;
  ASN1_STRING *pAVar5;
  uint uVar6;
  uchar *puVar7;
  ulong uVar8;
  char *pcVar9;
  undefined4 uVar10;
  ASN1_TIME *t;
  undefined4 uVar11;
  ASN1_TYPE *unaff_s0;
  int *piVar12;
  code *pcVar13;
  uchar *local_1f8;
  uchar *local_1f4;
  uchar *local_1f0;
  uchar *local_1ec;
  int local_1e8;
  int local_1e4;
  uchar *local_1e0;
  undefined4 local_1dc;
  char *local_1d8;
  int local_1d4 [4];
  char *local_1c4;
  ASN1_TYPE local_1c0 [50];
  int local_30;
  int local_2c;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_1d4[0] = -1;
  local_1d4[1] = -1;
  local_1d4[3] = 1;
  local_1f8 = (uchar *)0x0;
  local_30 = 0;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  iVar2 = (*(code *)PTR_CONF_parse_list_006a87f8)(param_1,0x2c,1,asn1_cb,local_1d4);
  iVar3 = local_1d4[3];
  if (iVar2 != 0) {
    a = (ASN1_TYPE *)0x0;
    *param_4 = 0xc2;
    goto LAB_005655dc;
  }
  if (local_1d4[2] - 0x10U < 2) {
    if (param_2 == 0) {
      a = (ASN1_TYPE *)0x0;
      *param_4 = 0xc0;
      goto LAB_005655dc;
    }
    if (0x31 < param_3) {
      a = (ASN1_TYPE *)0x0;
      *param_4 = 0xb5;
      goto LAB_005655dc;
    }
    local_1e0 = (uchar *)0x0;
    iVar3 = (*(code *)PTR_sk_new_null_006a6fa4)();
    if (iVar3 == 0) {
      a = (ASN1_TYPE *)0x0;
      unaff_s0 = a;
      if (local_1e0 == (uchar *)0x0) goto LAB_005655d8;
      iVar2 = 0;
LAB_005655a0:
      (*(code *)PTR_CRYPTO_free_006a6e88)();
      if (iVar3 != 0) {
        (*(code *)PTR_sk_pop_free_006a7058)(iVar3,PTR_ASN1_TYPE_free_006a7498);
      }
    }
    else {
      if (local_1c4 == (char *)0x0) {
        iVar2 = 0;
LAB_00565438:
        pcVar13 = (code *)PTR_i2d_ASN1_SET_ANY_006a8dcc;
        if (local_1d4[2] != 0x11) {
          pcVar13 = (code *)PTR_i2d_ASN1_SEQUENCE_ANY_006a8dd0;
        }
        iVar4 = (*pcVar13)(iVar3,&local_1e0);
        if (iVar4 < 0) {
LAB_00565590:
          a = (ASN1_TYPE *)0x0;
          goto LAB_00565594;
        }
        a = ASN1_TYPE_new();
        if (a == (ASN1_TYPE *)0x0) goto LAB_00565594;
        pAVar5 = ASN1_STRING_type_new(local_1d4[2]);
        (a->value).asn1_string = pAVar5;
        if (pAVar5 == (ASN1_STRING *)0x0) goto LAB_00565594;
        a->type = local_1d4[2];
        pAVar5->length = iVar4;
        pAVar5->data = local_1e0;
        local_1e0 = (uchar *)0x0;
      }
      else {
        a = (ASN1_TYPE *)0x0;
        iVar2 = (*(code *)PTR_X509V3_get_section_006a8dc8)(param_2,local_1c4);
        if (iVar2 != 0) {
          for (; iVar4 = (*(code *)PTR_sk_num_006a6e2c)(iVar2), (int)a < iVar4;
              a = (ASN1_TYPE *)((int)&a->type + 1)) {
            iVar4 = (*(code *)PTR_sk_value_006a6e24)(iVar2,a);
            iVar4 = generate_v3(*(undefined4 *)(iVar4 + 8),param_2,param_3 + 1,param_4);
            if ((iVar4 == 0) || (iVar4 = (*(code *)PTR_sk_push_006a6fa8)(iVar3,iVar4), iVar4 == 0))
            goto LAB_00565590;
          }
          goto LAB_00565438;
        }
LAB_00565594:
        if (local_1e0 != (uchar *)0x0) goto LAB_005655a0;
      }
      (*(code *)PTR_sk_pop_free_006a7058)(iVar3,PTR_ASN1_TYPE_free_006a7498);
    }
    if (iVar2 != 0) {
      (*(code *)PTR_X509V3_section_free_006a8dd4)(param_2,iVar2);
    }
  }
  else {
    a = ASN1_TYPE_new();
    if (a == (ASN1_TYPE *)0x0) {
      (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0xb3,0x41,"asn1_gen.c",0x289);
      unaff_s0 = a;
      goto LAB_005655d8;
    }
    if (local_1c4 == (char *)0x0) {
      local_1c4 = "";
    }
    switch(local_1d4[2]) {
    default:
      uVar11 = 0xc4;
      uVar10 = 0x31c;
LAB_005659e4:
      (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0xb3,uVar11,"asn1_gen.c",uVar10);
      (*(code *)PTR_ERR_add_error_data_006a813c)(2,"string=",local_1c4);
      while( true ) {
        ASN1_TYPE_free(a);
        unaff_s0 = a;
LAB_005655d8:
        a = (ASN1_TYPE *)0x0;
LAB_005655dc:
        if (local_2c == *(int *)puVar1) break;
        (*(code *)PTR___stack_chk_fail_006a9ab0)();
        a = unaff_s0;
LAB_00565c28:
        uVar11 = 0x41;
        uVar10 = 0x2f4;
LAB_00565a74:
        (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0xb3,uVar11,"asn1_gen.c",uVar10);
      }
      return a;
    case 1:
      if (iVar3 != 1) {
        uVar11 = 0xbe;
        uVar10 = 0x29b;
        goto LAB_00565a74;
      }
      local_1dc = 0;
      local_1e0 = (uchar *)0x0;
      local_1d8 = local_1c4;
      iVar3 = (*(code *)PTR_X509V3_get_value_bool_006a8dd8)(&local_1e0,&a->value);
      if (iVar3 == 0) {
        uVar11 = 0xb0;
        uVar10 = 0x2a2;
        goto LAB_005659e4;
      }
      break;
    case 2:
    case 10:
      if (iVar3 != 1) {
        uVar11 = 0xb9;
        uVar10 = 0x2aa;
        goto LAB_00565a74;
      }
      pcVar9 = (char *)(*(code *)PTR_s2i_ASN1_INTEGER_006a6fb4)(0,local_1c4);
      (a->value).ptr = pcVar9;
      if (pcVar9 == (char *)0x0) {
        uVar11 = 0xb4;
        uVar10 = 0x2ae;
        goto LAB_005659e4;
      }
      break;
    case 3:
    case 4:
      pAVar5 = ASN1_STRING_new();
      (a->value).asn1_string = pAVar5;
      if (pAVar5 == (ASN1_STRING *)0x0) goto LAB_00565c28;
      if (iVar3 == 3) {
        puVar7 = (uchar *)(*(code *)PTR_string_to_hex_006a738c)(local_1c4,&local_1e4);
        if (puVar7 == (uchar *)0x0) {
          uVar11 = 0xb2;
          uVar10 = 0x2fb;
          goto LAB_005659e4;
        }
        pAVar5 = (a->value).asn1_string;
        pAVar5->data = puVar7;
        pAVar5->length = local_1e4;
        pAVar5->type = local_1d4[2];
      }
      else {
        if (iVar3 != 1) {
          if ((iVar3 != 4) || (local_1d4[2] != 3)) {
            uVar11 = 0xaf;
            uVar10 = 0x30f;
            goto LAB_00565a74;
          }
          iVar3 = (*(code *)PTR_CONF_parse_list_006a87f8)(local_1c4,0x2c,1,bitstr_cb,pAVar5);
          if (iVar3 == 0) {
            uVar11 = 0xbc;
            uVar10 = 0x309;
            goto LAB_005659e4;
          }
          break;
        }
        ASN1_STRING_set(pAVar5,local_1c4,-1);
      }
      if (local_1d4[2] == 3) {
        ((a->value).asn1_string)->flags = ((a->value).asn1_string)->flags & 0xfffffff0U | 8;
        a->type = 3;
        goto LAB_005654d0;
      }
      break;
    case 5:
      if (*local_1c4 != '\0') {
        uVar11 = 0xb6;
        uVar10 = 0x294;
        goto LAB_00565a74;
      }
      break;
    case 6:
      if (iVar3 != 1) {
        uVar11 = 0xbf;
        uVar10 = 0x2b5;
        goto LAB_00565a74;
      }
      pcVar9 = (char *)(*(code *)PTR_OBJ_txt2obj_006a7000)(local_1c4,0);
      (a->value).ptr = pcVar9;
      if (pcVar9 == (char *)0x0) {
        uVar11 = 0xb7;
        uVar10 = 0x2b9;
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
        uVar10 = 0x1001;
      }
      else {
        uVar10 = 0x1000;
        if (iVar3 != 2) {
          uVar11 = 0xb1;
          uVar10 = 0x2e3;
          goto LAB_00565a74;
        }
      }
      uVar8 = ASN1_tag2bit(local_1d4[2]);
      iVar3 = (*(code *)PTR_ASN1_mbstring_copy_006a8cd4)
                        (&a->value,local_1c4,0xffffffff,uVar10,uVar8);
      if (iVar3 < 1) {
        uVar11 = 0x41;
        uVar10 = 0x2e9;
        goto LAB_005659e4;
      }
      break;
    case 0x17:
    case 0x18:
      if (iVar3 != 1) {
        uVar11 = 0xc1;
        uVar10 = 0x2c1;
        goto LAB_00565a74;
      }
      pAVar5 = ASN1_STRING_new();
      (a->value).asn1_string = pAVar5;
      if (pAVar5 == (ASN1_STRING *)0x0) {
        uVar11 = 0x41;
        uVar10 = 0x2c5;
        goto LAB_005659e4;
      }
      iVar3 = ASN1_STRING_set(pAVar5,local_1c4,-1);
      if (iVar3 == 0) {
        uVar11 = 0x41;
        uVar10 = 0x2c9;
        goto LAB_005659e4;
      }
      t = (a->value).asn1_string;
      t->type = local_1d4[2];
      iVar3 = ASN1_TIME_check(t);
      if (iVar3 == 0) {
        uVar11 = 0xb8;
        uVar10 = 0x2ce;
        goto LAB_005659e4;
      }
    }
    a->type = local_1d4[2];
  }
LAB_005654d0:
  unaff_s0 = a;
  if (a == (ASN1_TYPE *)0x0) goto LAB_005655d8;
  if ((local_1d4[0] == -1) && (local_30 == 0)) goto LAB_005655dc;
  iVar3 = i2d_ASN1_TYPE(a,&local_1f8);
  ASN1_TYPE_free(a);
  local_1f4 = local_1f8;
  if (local_1d4[0] == -1) {
    uVar6 = 0;
    iVar2 = iVar3;
  }
  else {
    uVar6 = ASN1_get_object(&local_1f4,&local_1e8,&local_1e4,(int *)&local_1e0,iVar3);
    if ((uVar6 & 0x80) != 0) goto LAB_005655cc;
    iVar2 = iVar3 - ((int)local_1f4 - (int)local_1f8);
    if ((uVar6 & 1) == 0) {
      uVar6 = uVar6 & 0x20;
    }
    else {
      local_1e8 = 0;
      uVar6 = 2;
    }
    iVar3 = ASN1_object_size(0,local_1e8,local_1d4[0]);
  }
  a = local_1c0;
  if (0 < local_30) {
    iVar4 = 0;
    piVar12 = (int *)((int)a + local_30 * 0x14 + -0x14);
    do {
      iVar4 = iVar4 + 1;
      piVar12[4] = iVar3 + piVar12[3];
      iVar3 = ASN1_object_size(0,iVar3 + piVar12[3],*piVar12);
      piVar12 = piVar12 + -5;
    } while (iVar4 < local_30);
  }
  puVar7 = (uchar *)(*(code *)PTR_CRYPTO_malloc_006a7008)(iVar3,"asn1_gen.c",0xf5);
  if (puVar7 != (uchar *)0x0) {
    local_1f0 = puVar7;
    if (0 < local_30) {
      iVar4 = 0;
      do {
        ASN1_put_object(&local_1f0,a[1].type,a[2].type,a->type,(a->value).boolean);
        if (a[1].value.ptr != (char *)0x0) {
          *local_1f0 = '\0';
          local_1f0 = local_1f0 + 1;
        }
        iVar4 = iVar4 + 1;
        a = (ASN1_TYPE *)&a[2].value;
      } while (iVar4 < local_30);
    }
    if (local_1d4[0] != -1) {
      if ((local_1d4[1] == 0) && (local_1d4[0] - 0x10U < 2)) {
        uVar6 = 0x20;
      }
      ASN1_put_object(&local_1f0,uVar6,local_1e8,local_1d4[0],local_1d4[1]);
    }
    (*(code *)PTR_memcpy_006a9aec)(local_1f0,local_1f4,iVar2);
    local_1ec = puVar7;
    a = d2i_ASN1_TYPE((ASN1_TYPE **)0x0,&local_1ec,iVar3);
    if (local_1f8 != (uchar *)0x0) {
      (*(code *)PTR_CRYPTO_free_006a6e88)();
    }
    (*(code *)PTR_CRYPTO_free_006a6e88)(puVar7);
    unaff_s0 = a;
    goto LAB_005655dc;
  }
LAB_005655cc:
  unaff_s0 = a;
  if (local_1f8 == (uchar *)0x0) goto LAB_005655d8;
  (*(code *)PTR_CRYPTO_free_006a6e88)();
  goto LAB_005655d8;
}

