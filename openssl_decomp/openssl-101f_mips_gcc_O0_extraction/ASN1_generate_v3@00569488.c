
ASN1_TYPE * ASN1_generate_v3(char *str,X509V3_CTX *cnf)

{
  undefined *puVar1;
  int iVar2;
  ASN1_TYPE *a;
  int iVar3;
  ASN1_TYPE *pAVar4;
  ASN1_STRING *pAVar5;
  uint uVar6;
  char *pcVar7;
  ulong uVar8;
  undefined4 uVar9;
  uchar *puVar10;
  ASN1_TIME *t;
  undefined4 uVar11;
  ASN1_TYPE *unaff_s0;
  ASN1_TYPE *unaff_s1;
  int *piVar12;
  int iVar13;
  code *pcVar14;
  uchar *local_1f8;
  uchar *local_1f4;
  ASN1_TYPE *local_1f0;
  ASN1_TYPE *local_1ec;
  int local_1e8;
  int local_1e4;
  uchar *local_1e0;
  undefined4 local_1dc;
  ASN1_TYPE *local_1d8;
  int local_1d4 [4];
  ASN1_TYPE *local_1c4;
  ASN1_TYPE local_1c0 [50];
  int local_30;
  int local_2c;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_1d4[0] = -1;
  local_1d4[1] = -1;
  local_1d4[3] = 1;
  local_1f8 = (uchar *)0x0;
  local_30 = 0;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  iVar2 = (*(code *)PTR_CONF_parse_list_006a9918)(str,0x2c,1,asn1_cb,local_1d4);
  iVar3 = local_1d4[3];
  if (iVar2 != 0) goto LAB_005697b0;
  if (local_1d4[2] - 0x10U < 2) {
    if (cnf == (X509V3_CTX *)0x0) {
      (*(code *)PTR_ERR_put_error_006a9030)(0xd,0xb2,0xc0,"asn1_gen.c",0xa3);
      goto LAB_005697b0;
    }
    local_1e0 = (uchar *)0x0;
    iVar3 = (*(code *)PTR_sk_new_null_006a80a4)();
    if (iVar3 == 0) {
      a = (ASN1_TYPE *)0x0;
      if (local_1e0 == (uchar *)0x0) goto LAB_005697b4;
      a = (ASN1_TYPE *)0x0;
      unaff_s1 = (ASN1_TYPE *)0x0;
LAB_00569778:
      (*(code *)PTR_CRYPTO_free_006a7f88)();
      if (iVar3 != 0) {
        (*(code *)PTR_sk_pop_free_006a8158)(iVar3,PTR_ASN1_TYPE_free_006a8598);
      }
    }
    else {
      if (local_1c4 == (ASN1_TYPE *)0x0) {
        unaff_s1 = (ASN1_TYPE *)0x0;
LAB_00569610:
        pcVar14 = (code *)PTR_i2d_ASN1_SET_ANY_006a9ef0;
        if (local_1d4[2] != 0x11) {
          pcVar14 = (code *)PTR_i2d_ASN1_SEQUENCE_ANY_006a9ef4;
        }
        iVar2 = (*pcVar14)(iVar3,&local_1e0);
        if (iVar2 < 0) {
LAB_00569768:
          a = (ASN1_TYPE *)0x0;
          goto LAB_00569770;
        }
        a = ASN1_TYPE_new();
        if (a == (ASN1_TYPE *)0x0) goto LAB_00569770;
        pAVar5 = ASN1_STRING_type_new(local_1d4[2]);
        (a->value).asn1_string = pAVar5;
        if (pAVar5 == (ASN1_STRING *)0x0) goto LAB_00569770;
        a->type = local_1d4[2];
        pAVar5->length = iVar2;
        pAVar5->data = local_1e0;
        local_1e0 = (uchar *)0x0;
      }
      else {
        a = (ASN1_TYPE *)0x0;
        unaff_s1 = (ASN1_TYPE *)(*(code *)PTR_X509V3_get_section_006a9eec)(cnf,local_1c4);
        if (unaff_s1 != (ASN1_TYPE *)0x0) {
          for (; iVar2 = (*(code *)PTR_sk_num_006a7f2c)(unaff_s1), (int)a < iVar2;
              a = (ASN1_TYPE *)((int)&a->type + 1)) {
            iVar2 = (*(code *)PTR_sk_value_006a7f24)(unaff_s1,a);
            pAVar4 = ASN1_generate_v3(*(char **)(iVar2 + 8),cnf);
            if ((pAVar4 == (ASN1_TYPE *)0x0) ||
               (iVar2 = (*(code *)PTR_sk_push_006a80a8)(iVar3,pAVar4), iVar2 == 0))
            goto LAB_00569768;
          }
          goto LAB_00569610;
        }
LAB_00569770:
        if (local_1e0 != (uchar *)0x0) goto LAB_00569778;
      }
      (*(code *)PTR_sk_pop_free_006a8158)(iVar3,PTR_ASN1_TYPE_free_006a8598);
    }
    if (unaff_s1 != (ASN1_TYPE *)0x0) {
      (*(code *)PTR_X509V3_section_free_006a9ef8)(cnf,unaff_s1);
    }
  }
  else {
    a = ASN1_TYPE_new();
    unaff_s1 = local_1c4;
    if (a == (ASN1_TYPE *)0x0) {
      (*(code *)PTR_ERR_put_error_006a9030)(0xd,0xb3,0x41,"asn1_gen.c",0x282);
      unaff_s0 = a;
      goto LAB_005697b0;
    }
    if (local_1c4 == (ASN1_TYPE *)0x0) {
      unaff_s1 = (ASN1_TYPE *)0x6395d0;
    }
    switch(local_1d4[2]) {
    default:
      uVar11 = 0xc4;
      uVar9 = 0x32e;
LAB_00569bc4:
      while( true ) {
        (*(code *)PTR_ERR_put_error_006a9030)(0xd,0xb3,uVar11,"asn1_gen.c",uVar9);
        (*(code *)PTR_ERR_add_error_data_006a9264)(2,"string=",unaff_s1);
LAB_00569bf4:
        ASN1_TYPE_free(a);
        unaff_s0 = a;
LAB_005697b0:
        a = (ASN1_TYPE *)0x0;
        local_1c4 = unaff_s0;
LAB_005697b4:
        if (local_2c == *(int *)puVar1) break;
        (*(code *)PTR___stack_chk_fail_006aabb8)();
        a = local_1c4;
LAB_00569e08:
        uVar11 = 0x41;
        uVar9 = 0x2c8;
      }
      return a;
    case 1:
      if (iVar3 != 1) {
        uVar11 = 0xbe;
        uVar9 = 0x297;
LAB_00569c3c:
        (*(code *)PTR_ERR_put_error_006a9030)(0xd,0xb3,uVar11,"asn1_gen.c",uVar9);
        goto LAB_00569bf4;
      }
      local_1dc = 0;
      local_1e0 = (uchar *)0x0;
      local_1d8 = unaff_s1;
      iVar3 = (*(code *)PTR_X509V3_get_value_bool_006a9efc)(&local_1e0,&a->value);
      if (iVar3 == 0) {
        uVar11 = 0xb0;
        uVar9 = 0x29f;
        goto LAB_00569bc4;
      }
      break;
    case 2:
    case 10:
      if (iVar3 != 1) {
        uVar11 = 0xb9;
        uVar9 = 0x2a8;
        goto LAB_00569c3c;
      }
      pcVar7 = (char *)(*(code *)PTR_s2i_ASN1_INTEGER_006a80b4)(0,unaff_s1);
      (a->value).ptr = pcVar7;
      if (pcVar7 == (char *)0x0) {
        uVar11 = 0xb4;
        uVar9 = 0x2ad;
        goto LAB_00569bc4;
      }
      break;
    case 3:
    case 4:
      pAVar5 = ASN1_STRING_new();
      (a->value).asn1_string = pAVar5;
      if (pAVar5 == (ASN1_STRING *)0x0) {
        uVar11 = 0x41;
        uVar9 = 0x2fe;
        goto LAB_00569c3c;
      }
      if (iVar3 == 3) {
        puVar10 = (uchar *)(*(code *)PTR_string_to_hex_006a848c)(unaff_s1,&local_1e4);
        if (puVar10 == (uchar *)0x0) {
          uVar11 = 0xb2;
          uVar9 = 0x307;
          goto LAB_00569bc4;
        }
        pAVar5 = (a->value).asn1_string;
        pAVar5->data = puVar10;
        pAVar5->length = local_1e4;
        pAVar5->type = local_1d4[2];
      }
      else {
        if (iVar3 != 1) {
          if ((iVar3 != 4) || (local_1d4[2] != 3)) {
            uVar11 = 0xaf;
            uVar9 = 0x31e;
            goto LAB_00569c3c;
          }
          iVar3 = (*(code *)PTR_CONF_parse_list_006a9918)(unaff_s1,0x2c,1,bitstr_cb,pAVar5);
          if (iVar3 == 0) {
            uVar11 = 0xbc;
            uVar9 = 0x316;
            goto LAB_00569bc4;
          }
          break;
        }
        ASN1_STRING_set(pAVar5,unaff_s1,-1);
      }
      if (local_1d4[2] == 3) {
        ((a->value).asn1_string)->flags = ((a->value).asn1_string)->flags & 0xfffffff0U | 8;
        a->type = 3;
        goto LAB_005696a8;
      }
      break;
    case 5:
      if (*(char *)&unaff_s1->type != '\0') {
        uVar11 = 0xb6;
        uVar9 = 0x28f;
        goto LAB_00569c3c;
      }
      break;
    case 6:
      if (iVar3 != 1) {
        uVar11 = 0xbf;
        uVar9 = 0x2b5;
        goto LAB_00569c3c;
      }
      pcVar7 = (char *)(*(code *)PTR_OBJ_txt2obj_006a8100)(unaff_s1,0);
      (a->value).ptr = pcVar7;
      if (pcVar7 == (char *)0x0) {
        uVar11 = 0xb7;
        uVar9 = 0x2ba;
        goto LAB_00569bc4;
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
        uVar9 = 0x1001;
      }
      else {
        uVar9 = 0x1000;
        if (iVar3 != 2) {
          uVar11 = 0xb1;
          uVar9 = 0x2e9;
          goto LAB_00569c3c;
        }
      }
      uVar8 = ASN1_tag2bit(local_1d4[2]);
      iVar3 = (*(code *)PTR_ASN1_mbstring_copy_006a9df8)(&a->value,unaff_s1,0xffffffff,uVar9,uVar8);
      if (iVar3 < 1) {
        uVar11 = 0x41;
        uVar9 = 0x2f1;
        goto LAB_00569bc4;
      }
      break;
    case 0x17:
    case 0x18:
      if (iVar3 != 1) {
        uVar11 = 0xc1;
        uVar9 = 0x2c3;
        goto LAB_00569c3c;
      }
      pAVar5 = ASN1_STRING_new();
      (a->value).asn1_string = pAVar5;
      if (pAVar5 == (ASN1_STRING *)0x0) goto LAB_00569e08;
      iVar3 = ASN1_STRING_set(pAVar5,unaff_s1,-1);
      if (iVar3 == 0) {
        uVar11 = 0x41;
        uVar9 = 0x2cd;
        goto LAB_00569bc4;
      }
      t = (a->value).asn1_string;
      t->type = local_1d4[2];
      iVar3 = ASN1_TIME_check(t);
      if (iVar3 == 0) {
        uVar11 = 0xb8;
        uVar9 = 0x2d3;
        goto LAB_00569bc4;
      }
    }
    a->type = local_1d4[2];
  }
LAB_005696a8:
  unaff_s0 = a;
  if (a == (ASN1_TYPE *)0x0) goto LAB_005697b0;
  local_1c4 = a;
  if ((local_1d4[0] == -1) && (local_30 == 0)) goto LAB_005697b4;
  iVar3 = i2d_ASN1_TYPE(a,&local_1f8);
  ASN1_TYPE_free(a);
  local_1f4 = local_1f8;
  if (local_1d4[0] == -1) {
    uVar6 = 0;
    iVar2 = iVar3;
  }
  else {
    uVar6 = ASN1_get_object(&local_1f4,&local_1e8,&local_1e4,(int *)&local_1e0,iVar3);
    if ((uVar6 & 0x80) != 0) goto LAB_005697a4;
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
  local_1c4 = local_1c0;
  if (0 < local_30) {
    iVar13 = 0;
    piVar12 = (int *)((int)local_1c4 + local_30 * 0x14 + -0x14);
    do {
      iVar13 = iVar13 + 1;
      piVar12[4] = iVar3 + piVar12[3];
      iVar3 = ASN1_object_size(0,iVar3 + piVar12[3],*piVar12);
      piVar12 = piVar12 + -5;
    } while (iVar13 < local_30);
  }
  unaff_s1 = (ASN1_TYPE *)(*(code *)PTR_CRYPTO_malloc_006a8108)(iVar3,"asn1_gen.c",0xe5);
  if (unaff_s1 != (ASN1_TYPE *)0x0) {
    local_1f0 = unaff_s1;
    if (0 < local_30) {
      iVar13 = 0;
      do {
        ASN1_put_object((uchar **)&local_1f0,local_1c4[1].type,local_1c4[2].type,local_1c4->type,
                        (local_1c4->value).boolean);
        if (local_1c4[1].value.ptr != (char *)0x0) {
          *(char *)&local_1f0->type = '\0';
          local_1f0 = (ASN1_TYPE *)((int)&local_1f0->type + 1);
        }
        iVar13 = iVar13 + 1;
        local_1c4 = (ASN1_TYPE *)&local_1c4[2].value;
      } while (iVar13 < local_30);
    }
    if (local_1d4[0] != -1) {
      if ((local_1d4[1] == 0) && (local_1d4[0] - 0x10U < 2)) {
        uVar6 = 0x20;
      }
      ASN1_put_object((uchar **)&local_1f0,uVar6,local_1e8,local_1d4[0],local_1d4[1]);
    }
    (*(code *)PTR_memcpy_006aabf4)(local_1f0,local_1f4,iVar2);
    local_1ec = unaff_s1;
    a = d2i_ASN1_TYPE((ASN1_TYPE **)0x0,(uchar **)&local_1ec,iVar3);
    if (local_1f8 != (uchar *)0x0) {
      (*(code *)PTR_CRYPTO_free_006a7f88)();
    }
    (*(code *)PTR_CRYPTO_free_006a7f88)(unaff_s1);
    local_1c4 = a;
    goto LAB_005697b4;
  }
LAB_005697a4:
  unaff_s0 = local_1c4;
  if (local_1f8 == (uchar *)0x0) goto LAB_005697b0;
  (*(code *)PTR_CRYPTO_free_006a7f88)();
  a = (ASN1_TYPE *)0x0;
  goto LAB_005697b4;
}

