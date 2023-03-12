
ASN1_TYPE * ASN1_generate_v3(char *str,X509V3_CTX *cnf)

{
  ASN1_TIME *t;
  uint uVar1;
  int iVar2;
  ASN1_TYPE *a;
  _STACK *st;
  _STACK *section;
  void *pvVar3;
  ASN1_TYPE *data;
  ASN1_STRING *pAVar4;
  size_t omax;
  uchar *puVar5;
  ulong mask;
  ASN1_OBJECT *pAVar6;
  ASN1_INTEGER *pAVar7;
  int *piVar8;
  int iVar9;
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
  iVar2 = CONF_parse_list(str,0x2c,1,asn1_cb,local_1c8);
  iVar9 = local_1c8[3];
  if (iVar2 != 0) goto LAB_0815150c;
  if (local_1c8[2] - 0x10U < 2) {
    if (cnf == (X509V3_CTX *)0x0) {
      ERR_put_error(0xd,0xb2,0xc0,"asn1_gen.c",0xa3);
      goto LAB_0815150c;
    }
    local_1d4.section = (char *)0x0;
    st = sk_new_null();
    if (st == (_STACK *)0x0) {
      if ((uchar *)local_1d4.section == (uchar *)0x0) goto LAB_0815150c;
      a = (ASN1_TYPE *)0x0;
      section = (_STACK *)0x0;
LAB_081514de:
      CRYPTO_free(local_1d4.section);
      if (st != (_STACK *)0x0) goto LAB_081513f8;
    }
    else {
      if (local_1b8 == (uchar *)0x0) {
        section = (_STACK *)0x0;
LAB_08151388:
        if (local_1c8[2] == 0x11) {
          local_1f4 = i2d_ASN1_SET_ANY((ASN1_SEQUENCE_ANY *)st,(uchar **)&local_1d4);
        }
        else {
          local_1f4 = i2d_ASN1_SEQUENCE_ANY((ASN1_SEQUENCE_ANY *)st,(uchar **)&local_1d4);
        }
        if ((int)local_1f4 < 0) {
LAB_081514d0:
          a = (ASN1_TYPE *)0x0;
          goto LAB_081514d2;
        }
        a = ASN1_TYPE_new();
        if (a == (ASN1_TYPE *)0x0) goto LAB_081514d2;
        pAVar4 = ASN1_STRING_type_new(local_1c8[2]);
        (a->value).asn1_string = pAVar4;
        if (pAVar4 == (ASN1_STRING *)0x0) goto LAB_081514d2;
        a->type = local_1c8[2];
        pAVar4->data = (uchar *)local_1d4.section;
        pAVar4->length = local_1f4;
        local_1d4.section = (char *)0x0;
      }
      else {
        a = (ASN1_TYPE *)0x0;
        section = (_STACK *)X509V3_get_section(cnf,(char *)local_1b8);
        if (section != (_STACK *)0x0) {
          for (; iVar9 = sk_num(section), (int)a < iVar9; a = (ASN1_TYPE *)((int)&a->type + 1)) {
            pvVar3 = sk_value(section,(int)a);
            data = ASN1_generate_v3(*(char **)((int)pvVar3 + 8),cnf);
            if ((data == (ASN1_TYPE *)0x0) || (iVar9 = sk_push(st,data), iVar9 == 0))
            goto LAB_081514d0;
          }
          goto LAB_08151388;
        }
LAB_081514d2:
        if ((uchar *)local_1d4.section != (uchar *)0x0) goto LAB_081514de;
      }
LAB_081513f8:
      sk_pop_free(st,ASN1_TYPE_free);
    }
    if (section != (_STACK *)0x0) {
      X509V3_section_free(cnf,(stack_st_CONF_VALUE *)section);
    }
LAB_0815141a:
    if (a == (ASN1_TYPE *)0x0) goto LAB_0815150c;
    if ((local_1c8[0] == -1) && (local_24 == 0)) goto LAB_0815150e;
    omax = i2d_ASN1_TYPE(a,&local_1ec);
    ASN1_TYPE_free(a);
    local_1e8 = local_1ec;
    if (local_1c8[0] == -1) {
      local_1f4 = 0;
      local_1f0 = omax;
LAB_0815153c:
      if (0 < local_24) {
        iVar9 = 0;
        piVar8 = local_1c8 + local_24 * 5;
        do {
          iVar9 = iVar9 + 1;
          piVar8[4] = omax + piVar8[3];
          omax = ASN1_object_size(0,omax + piVar8[3],*piVar8);
          piVar8 = piVar8 + -5;
        } while (iVar9 < local_24);
      }
      puVar5 = (uchar *)CRYPTO_malloc(omax,"asn1_gen.c",0xe5);
      if (puVar5 != (uchar *)0x0) {
        iVar9 = 0;
        piVar8 = local_1b4;
        local_1e4 = puVar5;
        if (0 < local_24) {
          do {
            ASN1_put_object(&local_1e4,piVar8[2],piVar8[4],*piVar8,piVar8[1]);
            if (piVar8[3] != 0) {
              *local_1e4 = '\0';
              local_1e4 = local_1e4 + 1;
            }
            iVar9 = iVar9 + 1;
            piVar8 = piVar8 + 5;
          } while (iVar9 < local_24);
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
        local_1e0 = puVar5;
        a = d2i_ASN1_TYPE((ASN1_TYPE **)0x0,&local_1e0,omax);
        if (local_1ec != (uchar *)0x0) {
          CRYPTO_free(local_1ec);
        }
        CRYPTO_free(puVar5);
        goto LAB_0815150e;
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
        goto LAB_0815153c;
      }
    }
    if (local_1ec != (uchar *)0x0) {
      CRYPTO_free(local_1ec);
      a = (ASN1_TYPE *)0x0;
      goto LAB_0815150e;
    }
    goto LAB_0815150c;
  }
  a = ASN1_TYPE_new();
  if (a == (ASN1_TYPE *)0x0) {
    ERR_put_error(0xd,0xb3,0x41,"asn1_gen.c",0x282);
    goto LAB_0815150c;
  }
  if (local_1b8 == (uchar *)0x0) {
    local_1b8 = "";
  }
  switch(local_1c8[2]) {
  default:
    ERR_put_error(0xd,0xb3,0xc4,"asn1_gen.c",0x32e);
    goto LAB_08151961;
  case 1:
    if (iVar9 == 1) {
      local_1d4.name = (char *)0x0;
      local_1d4.section = (char *)0x0;
      local_1d4.value = (char *)local_1b8;
      iVar9 = X509V3_get_value_bool(&local_1d4,&(a->value).boolean);
      if (iVar9 != 0) goto LAB_08151930;
      ERR_put_error(0xd,0xb3,0xb0,"asn1_gen.c",0x29f);
      goto LAB_08151961;
    }
    ERR_put_error(0xd,0xb3,0xbe,"asn1_gen.c",0x297);
    break;
  case 2:
  case 10:
    if (iVar9 == 1) {
      pAVar7 = s2i_ASN1_INTEGER((X509V3_EXT_METHOD *)0x0,(char *)local_1b8);
      (a->value).integer = pAVar7;
      if (pAVar7 != (ASN1_INTEGER *)0x0) goto LAB_08151930;
      ERR_put_error(0xd,0xb3,0xb4,"asn1_gen.c",0x2ad);
      goto LAB_08151961;
    }
    ERR_put_error(0xd,0xb3,0xb9,"asn1_gen.c",0x2a8);
    break;
  case 3:
  case 4:
    pAVar4 = ASN1_STRING_new();
    (a->value).asn1_string = pAVar4;
    if (pAVar4 != (ASN1_STRING *)0x0) {
      if (iVar9 == 3) {
        puVar5 = string_to_hex((char *)local_1b8,&local_1d8);
        if (puVar5 == (uchar *)0x0) {
          ERR_put_error(0xd,0xb3,0xb2,"asn1_gen.c",0x307);
          goto LAB_08151961;
        }
        pAVar4 = (a->value).asn1_string;
        pAVar4->data = puVar5;
        pAVar4->length = local_1d8;
        pAVar4->type = local_1c8[2];
      }
      else {
        if (iVar9 != 1) {
          if ((iVar9 == 4) && (local_1c8[2] == 3)) {
            iVar9 = CONF_parse_list((char *)local_1b8,0x2c,1,bitstr_cb,pAVar4);
            if (iVar9 != 0) goto LAB_08151930;
            ERR_put_error(0xd,0xb3,0xbc,"asn1_gen.c",0x316);
            goto LAB_08151961;
          }
          ERR_put_error(0xd,0xb3,0xaf,"asn1_gen.c",0x31e);
          break;
        }
        ASN1_STRING_set(pAVar4,local_1b8,-1);
      }
      if (local_1c8[2] == 3) {
        ((a->value).asn1_string)->flags = ((a->value).asn1_string)->flags & 0xfffffff0U | 8;
      }
LAB_08151930:
      a->type = local_1c8[2];
      goto LAB_0815141a;
    }
    ERR_put_error(0xd,0xb3,0x41,"asn1_gen.c",0x2fe);
    break;
  case 5:
    if (*local_1b8 == '\0') goto LAB_08151930;
    ERR_put_error(0xd,0xb3,0xb6,"asn1_gen.c",0x28f);
    break;
  case 6:
    if (iVar9 == 1) {
      pAVar6 = OBJ_txt2obj((char *)local_1b8,0);
      (a->value).object = pAVar6;
      if (pAVar6 != (ASN1_OBJECT *)0x0) goto LAB_08151930;
      ERR_put_error(0xd,0xb3,0xb7,"asn1_gen.c",0x2ba);
      goto LAB_08151961;
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
    if (iVar9 == 1) {
      iVar2 = 0x1001;
    }
    else {
      iVar2 = 0x1000;
      if (iVar9 != 2) {
        ERR_put_error(0xd,0xb3,0xb1,"asn1_gen.c",0x2e9);
        break;
      }
    }
    mask = ASN1_tag2bit(local_1c8[2]);
    iVar9 = ASN1_mbstring_copy(&(a->value).asn1_string,local_1b8,-1,iVar2,mask);
    if (0 < iVar9) goto LAB_08151930;
    iVar9 = 0x2f1;
LAB_0815177e:
    ERR_put_error(0xd,0xb3,0x41,"asn1_gen.c",iVar9);
LAB_08151961:
    ERR_add_error_data(2,"string=",local_1b8);
    break;
  case 0x17:
  case 0x18:
    if (iVar9 == 1) {
      pAVar4 = ASN1_STRING_new();
      (a->value).asn1_string = pAVar4;
      if (pAVar4 == (ASN1_STRING *)0x0) {
        iVar9 = 0x2c8;
      }
      else {
        iVar9 = ASN1_STRING_set(pAVar4,local_1b8,-1);
        if (iVar9 != 0) {
          t = (a->value).asn1_string;
          t->type = local_1c8[2];
          iVar9 = ASN1_TIME_check(t);
          if (iVar9 != 0) goto LAB_08151930;
          ERR_put_error(0xd,0xb3,0xb8,"asn1_gen.c",0x2d3);
          goto LAB_08151961;
        }
        iVar9 = 0x2cd;
      }
      goto LAB_0815177e;
    }
    ERR_put_error(0xd,0xb3,0xc1,"asn1_gen.c",0x2c3);
  }
  ASN1_TYPE_free(a);
LAB_0815150c:
  a = (ASN1_TYPE *)0x0;
LAB_0815150e:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return a;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

