
ASN1_TYPE * __regparm3
generate_v3(char *param_1_00,X509V3_CTX *param_2,int param_3,undefined4 *param_1)

{
  ASN1_TIME *t;
  uint uVar1;
  int iVar2;
  ASN1_TYPE *a;
  _STACK *st;
  _STACK *section;
  void *data;
  ASN1_STRING *pAVar3;
  size_t omax;
  uchar *puVar4;
  ulong mask;
  ASN1_OBJECT *pAVar5;
  ASN1_INTEGER *pAVar6;
  int iVar7;
  int *piVar8;
  int in_GS_OFFSET;
  uint local_1f4;
  size_t local_1f0;
  uchar *local_1ec;
  uchar *local_1e8;
  uchar *local_1e4;
  uchar *local_1e0;
  int local_1dc;
  int local_1d8;
  CONF_VALUE local_1d4;
  int local_1c8 [4];
  uchar *local_1b8;
  int local_1b4 [100];
  int local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_1ec = (uchar *)0x0;
  local_1c8[0] = -1;
  local_1c8[1] = -1;
  local_1c8[3] = 1;
  local_24 = 0;
  iVar2 = CONF_parse_list(param_1_00,0x2c,1,asn1_cb,local_1c8);
  iVar7 = local_1c8[3];
  if (iVar2 != 0) {
    *param_1 = 0xc2;
    a = (ASN1_TYPE *)0x0;
    goto LAB_0814e968;
  }
  if (local_1c8[2] - 0x10U < 2) {
    if (param_2 == (X509V3_CTX *)0x0) {
      *param_1 = 0xc0;
      a = (ASN1_TYPE *)0x0;
      goto LAB_0814e968;
    }
    if (0x31 < param_3) {
      *param_1 = 0xb5;
      a = (ASN1_TYPE *)0x0;
      goto LAB_0814e968;
    }
    local_1d4.section = (char *)0x0;
    st = sk_new_null();
    if (st != (_STACK *)0x0) {
      if (local_1b8 == (uchar *)0x0) {
        section = (_STACK *)0x0;
LAB_0814e6d1:
        if (local_1c8[2] == 0x11) {
          iVar7 = i2d_ASN1_SET_ANY((ASN1_SEQUENCE_ANY *)st,(uchar **)&local_1d4);
        }
        else {
          iVar7 = i2d_ASN1_SEQUENCE_ANY((ASN1_SEQUENCE_ANY *)st,(uchar **)&local_1d4);
        }
        if (iVar7 < 0) goto LAB_0814ec68;
        a = ASN1_TYPE_new();
        if (a == (ASN1_TYPE *)0x0) goto LAB_0814ec6a;
        pAVar3 = ASN1_STRING_type_new(local_1c8[2]);
        (a->value).asn1_string = pAVar3;
        if (pAVar3 == (ASN1_STRING *)0x0) goto LAB_0814ec6a;
        a->type = local_1c8[2];
        pAVar3->data = (uchar *)local_1d4.section;
        pAVar3->length = iVar7;
        local_1d4.section = (char *)0x0;
      }
      else {
        section = (_STACK *)X509V3_get_section(param_2,(char *)local_1b8);
        if (section != (_STACK *)0x0) {
          for (iVar7 = 0; iVar2 = sk_num(section), iVar7 < iVar2; iVar7 = iVar7 + 1) {
            sk_value(section,iVar7);
            data = (void *)generate_v3(param_1);
            if ((data == (void *)0x0) || (iVar2 = sk_push(st,data), iVar2 == 0)) goto LAB_0814ec68;
          }
          goto LAB_0814e6d1;
        }
LAB_0814ec68:
        a = (ASN1_TYPE *)0x0;
LAB_0814ec6a:
        if ((uchar *)local_1d4.section != (uchar *)0x0) goto LAB_0814ec76;
      }
LAB_0814e73b:
      sk_pop_free(st,ASN1_TYPE_free);
LAB_0814e74f:
      if (section != (_STACK *)0x0) {
        X509V3_section_free(param_2,(stack_st_CONF_VALUE *)section);
      }
      goto LAB_0814e760;
    }
    if ((uchar *)local_1d4.section != (uchar *)0x0) {
      a = (ASN1_TYPE *)0x0;
      section = (_STACK *)0x0;
LAB_0814ec76:
      CRYPTO_free(local_1d4.section);
      if (st != (_STACK *)0x0) goto LAB_0814e73b;
      goto LAB_0814e74f;
    }
    goto LAB_0814ec48;
  }
  a = ASN1_TYPE_new();
  if (a == (ASN1_TYPE *)0x0) {
    ERR_put_error(0xd,0xb3,0x41,"asn1_gen.c",0x289);
    a = (ASN1_TYPE *)0x0;
    goto LAB_0814e968;
  }
  if (local_1b8 == (uchar *)0x0) {
    local_1b8 = "";
  }
  switch(local_1c8[2]) {
  default:
    ERR_put_error(0xd,0xb3,0xc4,"asn1_gen.c",0x31c);
    goto LAB_0814ec29;
  case 1:
    if (iVar7 == 1) {
      local_1d4.name = (char *)0x0;
      local_1d4.section = (char *)0x0;
      local_1d4.value = (char *)local_1b8;
      iVar7 = X509V3_get_value_bool(&local_1d4,&(a->value).boolean);
      if (iVar7 != 0) goto LAB_0814ebf8;
      ERR_put_error(0xd,0xb3,0xb0,"asn1_gen.c",0x2a2);
      goto LAB_0814ec29;
    }
    ERR_put_error(0xd,0xb3,0xbe,"asn1_gen.c",0x29b);
    break;
  case 2:
  case 10:
    if (iVar7 == 1) {
      pAVar6 = s2i_ASN1_INTEGER((X509V3_EXT_METHOD *)0x0,(char *)local_1b8);
      (a->value).integer = pAVar6;
      if (pAVar6 != (ASN1_INTEGER *)0x0) goto LAB_0814ebf8;
      ERR_put_error(0xd,0xb3,0xb4,"asn1_gen.c",0x2ae);
      goto LAB_0814ec29;
    }
    ERR_put_error(0xd,0xb3,0xb9,"asn1_gen.c",0x2aa);
    break;
  case 3:
  case 4:
    pAVar3 = ASN1_STRING_new();
    (a->value).asn1_string = pAVar3;
    if (pAVar3 != (ASN1_STRING *)0x0) {
      if (iVar7 == 3) {
        puVar4 = string_to_hex((char *)local_1b8,&local_1d8);
        if (puVar4 == (uchar *)0x0) {
          ERR_put_error(0xd,0xb3,0xb2,"asn1_gen.c",0x2fb);
          goto LAB_0814ec29;
        }
        pAVar3 = (a->value).asn1_string;
        pAVar3->data = puVar4;
        pAVar3->length = local_1d8;
        pAVar3->type = local_1c8[2];
      }
      else {
        if (iVar7 != 1) {
          if ((iVar7 == 4) && (local_1c8[2] == 3)) {
            iVar7 = CONF_parse_list((char *)local_1b8,0x2c,1,bitstr_cb,pAVar3);
            if (iVar7 != 0) goto LAB_0814ebf8;
            ERR_put_error(0xd,0xb3,0xbc,"asn1_gen.c",0x309);
            goto LAB_0814ec29;
          }
          ERR_put_error(0xd,0xb3,0xaf,"asn1_gen.c",0x30f);
          break;
        }
        ASN1_STRING_set(pAVar3,local_1b8,-1);
      }
      if (local_1c8[2] == 3) {
        ((a->value).asn1_string)->flags = ((a->value).asn1_string)->flags & 0xfffffff0U | 8;
      }
LAB_0814ebf8:
      a->type = local_1c8[2];
LAB_0814e760:
      if (a == (ASN1_TYPE *)0x0) goto LAB_0814ec48;
      if ((local_1c8[0] == -1) && (local_24 == 0)) goto LAB_0814e968;
      omax = i2d_ASN1_TYPE(a,&local_1ec);
      ASN1_TYPE_free(a);
      local_1e8 = local_1ec;
      if (local_1c8[0] == -1) {
        local_1f4 = 0;
        local_1f0 = omax;
LAB_0814e812:
        if (0 < local_24) {
          iVar7 = 0;
          piVar8 = local_1c8 + local_24 * 5;
          do {
            iVar7 = iVar7 + 1;
            piVar8[4] = omax + piVar8[3];
            omax = ASN1_object_size(0,omax + piVar8[3],*piVar8);
            piVar8 = piVar8 + -5;
          } while (iVar7 < local_24);
        }
        puVar4 = (uchar *)CRYPTO_malloc(omax,"asn1_gen.c",0xf5);
        if (puVar4 != (uchar *)0x0) {
          iVar7 = 0;
          piVar8 = local_1b4;
          local_1e4 = puVar4;
          if (0 < local_24) {
            do {
              ASN1_put_object(&local_1e4,piVar8[2],piVar8[4],*piVar8,piVar8[1]);
              if (piVar8[3] != 0) {
                *local_1e4 = '\0';
                local_1e4 = local_1e4 + 1;
              }
              iVar7 = iVar7 + 1;
              piVar8 = piVar8 + 5;
            } while (iVar7 < local_24);
          }
          if (local_1c8[0] != -1) {
            uVar1 = local_1f4;
            if ((local_1c8[1] == 0) && (uVar1 = 0x20, 1 < local_1c8[0] - 0x10U)) {
              uVar1 = local_1f4;
            }
            local_1f4 = uVar1;
            ASN1_put_object(&local_1e4,local_1f4,local_1dc,local_1c8[0],local_1c8[1]);
          }
          memcpy(local_1e4,local_1e8,local_1f0);
          local_1e0 = puVar4;
          a = d2i_ASN1_TYPE((ASN1_TYPE **)0x0,&local_1e0,omax);
          if (local_1ec != (uchar *)0x0) {
            CRYPTO_free(local_1ec);
          }
          CRYPTO_free(puVar4);
          goto LAB_0814e968;
        }
      }
      else {
        local_1f4 = ASN1_get_object(&local_1e8,&local_1dc,&local_1d8,(int *)&local_1d4,omax);
        if ((local_1f4 & 0x80) == 0) {
          local_1f0 = omax - ((int)local_1e8 - (int)local_1ec);
          if ((local_1f4 & 1) == 0) {
            local_1f4 = local_1f4 & 0x20;
          }
          else {
            local_1dc = 0;
            local_1f4 = 2;
          }
          omax = ASN1_object_size(0,local_1dc,local_1c8[0]);
          goto LAB_0814e812;
        }
      }
      if (local_1ec != (uchar *)0x0) {
        CRYPTO_free(local_1ec);
        a = (ASN1_TYPE *)0x0;
        goto LAB_0814e968;
      }
      goto LAB_0814ec48;
    }
    ERR_put_error(0xd,0xb3,0x41,"asn1_gen.c",0x2f4);
    break;
  case 5:
    if (*local_1b8 == '\0') goto LAB_0814ebf8;
    ERR_put_error(0xd,0xb3,0xb6,"asn1_gen.c",0x294);
    break;
  case 6:
    if (iVar7 == 1) {
      pAVar5 = OBJ_txt2obj((char *)local_1b8,0);
      (a->value).object = pAVar5;
      if (pAVar5 != (ASN1_OBJECT *)0x0) goto LAB_0814ebf8;
      ERR_put_error(0xd,0xb3,0xb7,"asn1_gen.c",0x2b9);
      goto LAB_0814ec29;
    }
    ERR_put_error(0xd,0xb3,0xbf,"asn1_gen.c",0x2b5);
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
    if (iVar7 == 1) {
      iVar2 = 0x1001;
    }
    else {
      iVar2 = 0x1000;
      if (iVar7 != 2) {
        ERR_put_error(0xd,0xb3,0xb1,"asn1_gen.c",0x2e3);
        break;
      }
    }
    mask = ASN1_tag2bit(local_1c8[2]);
    iVar7 = ASN1_mbstring_copy(&(a->value).asn1_string,local_1b8,-1,iVar2,mask);
    if (0 < iVar7) goto LAB_0814ebf8;
    iVar7 = 0x2e9;
LAB_0814ea4e:
    ERR_put_error(0xd,0xb3,0x41,"asn1_gen.c",iVar7);
LAB_0814ec29:
    ERR_add_error_data(2,"string=",local_1b8);
    break;
  case 0x17:
  case 0x18:
    if (iVar7 == 1) {
      pAVar3 = ASN1_STRING_new();
      (a->value).asn1_string = pAVar3;
      if (pAVar3 == (ASN1_STRING *)0x0) {
        iVar7 = 0x2c5;
      }
      else {
        iVar7 = ASN1_STRING_set(pAVar3,local_1b8,-1);
        if (iVar7 != 0) {
          t = (a->value).asn1_string;
          t->type = local_1c8[2];
          iVar7 = ASN1_TIME_check(t);
          if (iVar7 != 0) goto LAB_0814ebf8;
          ERR_put_error(0xd,0xb3,0xb8,"asn1_gen.c",0x2ce);
          goto LAB_0814ec29;
        }
        iVar7 = 0x2c9;
      }
      goto LAB_0814ea4e;
    }
    ERR_put_error(0xd,0xb3,0xc1,"asn1_gen.c",0x2c1);
  }
  ASN1_TYPE_free(a);
LAB_0814ec48:
  a = (ASN1_TYPE *)0x0;
LAB_0814e968:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return a;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

