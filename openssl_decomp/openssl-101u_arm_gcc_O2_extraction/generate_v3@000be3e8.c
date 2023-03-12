
/* WARNING: Type propagation algorithm not settling */

ASN1_TYPE * generate_v3(char *param_1,X509V3_CTX *param_2,int param_3,undefined4 *param_4)

{
  uchar *puVar1;
  ASN1_TYPE *pAVar2;
  _STACK *st;
  void *pvVar3;
  int iVar4;
  ASN1_STRING *pAVar5;
  X509V3_CTX *pXVar6;
  uchar *num;
  uchar *ptr;
  ASN1_TIME *t;
  ulong mask;
  ASN1_OBJECT *pAVar7;
  ASN1_INTEGER *pAVar8;
  uint length;
  uint *puVar9;
  int *piVar10;
  X509V3_CTX *inform;
  bool bVar11;
  X509V3_CTX *local_1fc;
  uchar *local_1f4;
  uchar *local_1f0;
  uchar *local_1ec;
  uchar *local_1e8;
  uint local_1e4 [2];
  CONF_VALUE local_1dc;
  int local_1d0;
  int local_1cc;
  int local_1c8;
  X509V3_CTX *local_1c4;
  _STACK *local_1c0;
  int aiStack_1bc [100];
  int local_2c;
  
  local_1c4 = (X509V3_CTX *)0x1;
  local_2c = 0;
  local_1d0 = -1;
  local_1cc = -1;
  local_1f4 = (uchar *)0x0;
  puVar1 = (uchar *)CONF_parse_list(param_1,0x2c,1,asn1_cb + 1,&local_1d0);
  inform = local_1c4;
  if (puVar1 != (uchar *)0x0) {
    *param_4 = 0xc2;
    return (ASN1_TYPE *)0x0;
  }
  if (local_1c8 - 0x10U < 2) {
    if (param_2 == (X509V3_CTX *)0x0) {
      *param_4 = 0xc0;
      return (ASN1_TYPE *)0x0;
    }
    if (0x31 < param_3) {
      *param_4 = 0xb5;
      return (ASN1_TYPE *)0x0;
    }
    local_1dc.section = (char *)puVar1;
    st = sk_new_null();
    if (st == (_STACK *)0x0) {
LAB_000be95e:
      local_1c0 = (_STACK *)0x0;
      pAVar2 = (ASN1_TYPE *)0x0;
LAB_000be886:
      if ((uchar *)local_1dc.section != (uchar *)0x0) {
        CRYPTO_free(local_1dc.section);
      }
      if (st != (_STACK *)0x0) goto LAB_000be556;
    }
    else {
      if (local_1c0 != (_STACK *)0x0) {
        local_1c0 = (_STACK *)X509V3_get_section(param_2,(char *)local_1c0);
        if (local_1c0 == (_STACK *)0x0) goto LAB_000be95e;
        do {
          iVar4 = sk_num(local_1c0);
          if (iVar4 <= (int)puVar1) goto LAB_000be512;
          pvVar3 = sk_value(local_1c0,(int)puVar1);
          pAVar2 = (ASN1_TYPE *)
                   generate_v3(*(undefined4 *)((int)pvVar3 + 8),param_2,param_3 + 1,param_4);
        } while ((pAVar2 != (ASN1_TYPE *)0x0) &&
                (pAVar2 = (ASN1_TYPE *)sk_push(st,pAVar2), puVar1 = puVar1 + 1,
                pAVar2 != (ASN1_TYPE *)0x0));
        goto LAB_000be886;
      }
LAB_000be512:
      if (local_1c8 == 0x11) {
        iVar4 = i2d_ASN1_SET_ANY((ASN1_SEQUENCE_ANY *)st,(uchar **)&local_1dc);
      }
      else {
        iVar4 = i2d_ASN1_SEQUENCE_ANY((ASN1_SEQUENCE_ANY *)st,(uchar **)&local_1dc);
      }
      if (iVar4 < 0) {
        pAVar2 = (ASN1_TYPE *)0x0;
        goto LAB_000be886;
      }
      pAVar2 = ASN1_TYPE_new();
      if (pAVar2 == (ASN1_TYPE *)0x0) goto LAB_000be886;
      pAVar5 = ASN1_STRING_type_new(local_1c8);
      (pAVar2->value).asn1_string = pAVar5;
      if (pAVar5 == (ASN1_STRING *)0x0) goto LAB_000be886;
      pAVar2->type = local_1c8;
      pAVar5->length = iVar4;
      pAVar5->data = (uchar *)local_1dc.section;
      local_1dc.section = (char *)0x0;
LAB_000be556:
      sk_pop_free(st,ASN1_TYPE_free);
    }
    inform = param_2;
    if (local_1c0 != (_STACK *)0x0) {
      X509V3_section_free(param_2,(stack_st_CONF_VALUE *)local_1c0);
    }
    goto LAB_000be56e;
  }
  pAVar2 = ASN1_TYPE_new();
  if (pAVar2 == (ASN1_TYPE *)0x0) {
    ERR_put_error(0xd,0xb3,0x41,"asn1_gen.c",0x289);
    return (ASN1_TYPE *)0;
  }
  if (local_1c0 == (_STACK *)0x0) {
    local_1c0 = (_STACK *)0x12afd8;
  }
  switch(local_1c8) {
  case 1:
    if (inform != (X509V3_CTX *)0x1) {
      ERR_put_error(0xd,0xb3,0xbe,"asn1_gen.c",0x29b);
      goto LAB_000be872;
    }
    local_1dc.name = (char *)0x0;
    local_1dc.section = (char *)0x0;
    local_1dc.value = (char *)local_1c0;
    iVar4 = X509V3_get_value_bool(&local_1dc,&(pAVar2->value).boolean);
    if (iVar4 != 0) goto LAB_000be844;
    ERR_put_error(0xd,0xb3,0xb0,"asn1_gen.c",0x2a2);
    break;
  case 2:
  case 10:
    if (inform != (X509V3_CTX *)0x1) {
      ERR_put_error(0xd,0xb3,0xb9,"asn1_gen.c",0x2aa);
      goto LAB_000be872;
    }
    pAVar8 = s2i_ASN1_INTEGER((X509V3_EXT_METHOD *)0x0,(char *)local_1c0);
    (pAVar2->value).integer = pAVar8;
    if (pAVar8 != (ASN1_INTEGER *)0x0) goto LAB_000be844;
    ERR_put_error(0xd,0xb3,0xb4,"asn1_gen.c",0x2ae);
    break;
  case 3:
  case 4:
    pAVar5 = ASN1_STRING_new();
    (pAVar2->value).asn1_string = pAVar5;
    if (pAVar5 == (ASN1_STRING *)0x0) {
      ERR_put_error(0xd,0xb3,0x41,"asn1_gen.c",0x2f4);
      goto LAB_000be872;
    }
    if (inform == (X509V3_CTX *)0x3) {
      puVar1 = string_to_hex((char *)local_1c0,(long *)(local_1e4 + 1));
      if (puVar1 != (uchar *)0x0) {
        pAVar5 = (pAVar2->value).asn1_string;
        pAVar5->length = local_1e4[1];
        pAVar5->data = puVar1;
        pAVar5->type = local_1c8;
        goto LAB_000be926;
      }
      ERR_put_error(0xd,0xb3,0xb2,"asn1_gen.c",0x2fb);
    }
    else {
      if (inform == (X509V3_CTX *)0x1) {
        ASN1_STRING_set(pAVar5,local_1c0,-1);
LAB_000be926:
        if (local_1c8 == 3) {
          ((pAVar2->value).asn1_string)->flags =
               ((pAVar2->value).asn1_string)->flags & 0xfffffff0U | 8;
        }
        goto LAB_000be844;
      }
      if (local_1c8 != 3 || inform != (X509V3_CTX *)&DAT_00000004) {
        ERR_put_error(0xd,0xb3,0xaf,"asn1_gen.c",0x30f);
        goto LAB_000be872;
      }
      iVar4 = CONF_parse_list((char *)local_1c0,0x2c,1,bitstr_cb + 1,pAVar5);
      if (iVar4 != 0) goto LAB_000be844;
      ERR_put_error(0xd,0xb3,0xbc,"asn1_gen.c",0x309);
    }
    break;
  case 5:
    if (*(char *)&local_1c0->num != '\0') {
      ERR_put_error(0xd,0xb3,0xb6,"asn1_gen.c",0x294);
      goto LAB_000be872;
    }
    goto LAB_000be844;
  case 6:
    if (inform != (X509V3_CTX *)0x1) {
      ERR_put_error(0xd,0xb3,0xbf,"asn1_gen.c",0x2b5);
      goto LAB_000be872;
    }
    pAVar7 = OBJ_txt2obj((char *)local_1c0,0);
    (pAVar2->value).object = pAVar7;
    if (pAVar7 != (ASN1_OBJECT *)0x0) goto LAB_000be844;
    ERR_put_error(0xd,0xb3,0xb7,"asn1_gen.c",0x2b9);
    break;
  default:
    ERR_put_error(0xd,0xb3,0xc4,"asn1_gen.c",0x31c);
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
    if (inform == (X509V3_CTX *)0x1) {
      inform = (X509V3_CTX *)0x1001;
    }
    else {
      if (inform != (X509V3_CTX *)0x2) {
        ERR_put_error(0xd,0xb3,0xb1,"asn1_gen.c",0x2e3);
        goto LAB_000be872;
      }
      inform = (X509V3_CTX *)0x1000;
    }
    mask = ASN1_tag2bit(local_1c8);
    iVar4 = ASN1_mbstring_copy(&(pAVar2->value).asn1_string,(uchar *)local_1c0,-1,(int)inform,mask);
    if (iVar4 < 1) {
      iVar4 = 0x2e9;
      goto LAB_000be74c;
    }
LAB_000be844:
    pAVar2->type = local_1c8;
LAB_000be56e:
    if (pAVar2 == (ASN1_TYPE *)0x0) {
      return (ASN1_TYPE *)0;
    }
    if ((local_1d0 == -1) && (local_2c == 0)) {
      return pAVar2;
    }
    puVar1 = (uchar *)i2d_ASN1_TYPE(pAVar2,&local_1f4);
    ASN1_TYPE_free(pAVar2);
    local_1f0 = local_1f4;
    if (local_1d0 == -1) {
      local_1fc = (X509V3_CTX *)0x0;
      num = puVar1;
LAB_000be5e6:
      if (0 < local_2c) {
        puVar9 = local_1e4 + local_2c * 5;
        iVar4 = 0;
        do {
          iVar4 = iVar4 + 1;
          puVar9[9] = (uint)(num + puVar9[8]);
          num = (uchar *)ASN1_object_size(0,(int)(num + puVar9[8]),puVar9[5]);
          puVar9 = puVar9 + -5;
        } while (iVar4 < local_2c);
      }
      ptr = (uchar *)CRYPTO_malloc((int)num,"asn1_gen.c",0xf5);
      if (ptr != (uchar *)0x0) {
        local_1ec = ptr;
        if (0 < local_2c) {
          iVar4 = 0;
          piVar10 = aiStack_1bc;
          do {
            iVar4 = iVar4 + 1;
            ASN1_put_object(&local_1ec,piVar10[2],piVar10[4],*piVar10,piVar10[1]);
            if (piVar10[3] != 0) {
              *local_1ec = '\0';
              local_1ec = local_1ec + 1;
            }
            piVar10 = piVar10 + 5;
          } while (iVar4 < local_2c);
        }
        if (local_1d0 != -1) {
          if ((local_1cc == 0) && (local_1d0 - 0x10U < 2)) {
            local_1fc = (X509V3_CTX *)0x20;
          }
          ASN1_put_object(&local_1ec,(int)local_1fc,local_1e4[0],local_1d0,local_1cc);
        }
        memcpy(local_1ec,local_1f0,(size_t)puVar1);
        local_1e8 = ptr;
        pAVar2 = d2i_ASN1_TYPE((ASN1_TYPE **)0x0,&local_1e8,(long)num);
        goto LAB_000be6b0;
      }
    }
    else {
      pXVar6 = (X509V3_CTX *)
               ASN1_get_object(&local_1f0,(long *)local_1e4,(int *)(local_1e4 + 1),(int *)&local_1dc
                               ,(long)puVar1);
      length = (uint)pXVar6 & 0x80;
      if (length == 0) {
        bVar11 = -1 < (int)pXVar6 << 0x1f;
        if (bVar11) {
          pXVar6 = (X509V3_CTX *)((uint)pXVar6 & 0x20);
          length = local_1e4[0];
        }
        else {
          inform = (X509V3_CTX *)0x2;
        }
        if (bVar11) {
          local_1fc = pXVar6;
        }
        puVar1 = local_1f4 + ((int)puVar1 - (int)local_1f0);
        if (!bVar11) {
          local_1fc = inform;
          local_1e4[0] = length;
        }
        num = (uchar *)ASN1_object_size(0,length,local_1d0);
        goto LAB_000be5e6;
      }
    }
    ptr = (uchar *)0x0;
    pAVar2 = (ASN1_TYPE *)0x0;
LAB_000be6b0:
    if (local_1f4 != (uchar *)0x0) {
      CRYPTO_free(local_1f4);
    }
    if (ptr != (uchar *)0x0) {
      CRYPTO_free(ptr);
      return pAVar2;
    }
    return pAVar2;
  case 0x17:
  case 0x18:
    if (inform != (X509V3_CTX *)0x1) {
      ERR_put_error(0xd,0xb3,0xc1,"asn1_gen.c",0x2c1);
      goto LAB_000be872;
    }
    pAVar5 = ASN1_STRING_new();
    (pAVar2->value).asn1_string = pAVar5;
    if (pAVar5 == (ASN1_STRING *)0x0) {
      iVar4 = 0x2c5;
    }
    else {
      iVar4 = ASN1_STRING_set(pAVar5,local_1c0,-1);
      if (iVar4 != 0) {
        t = (pAVar2->value).asn1_string;
        t->type = local_1c8;
        iVar4 = ASN1_TIME_check(t);
        if (iVar4 != 0) goto LAB_000be844;
        ERR_put_error(0xd,0xb3,0xb8,"asn1_gen.c",0x2ce);
        break;
      }
      iVar4 = 0x2c9;
    }
LAB_000be74c:
    ERR_put_error(0xd,0xb3,0x41,"asn1_gen.c",iVar4);
  }
  ERR_add_error_data(2,"string=",local_1c0);
LAB_000be872:
  ASN1_TYPE_free(pAVar2);
  return (ASN1_TYPE *)0x0;
}

