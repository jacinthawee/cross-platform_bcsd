
/* WARNING: Type propagation algorithm not settling */

ASN1_TYPE * ASN1_generate_v3(char *str,X509V3_CTX *cnf)

{
  uchar *puVar1;
  _STACK *a;
  _STACK *st;
  void *pvVar2;
  ASN1_STRING *pAVar3;
  X509V3_CTX *pXVar4;
  uchar *num;
  uchar *ptr;
  ASN1_TYPE *pAVar5;
  ASN1_INTEGER *pAVar6;
  ASN1_TIME *t;
  ulong mask;
  ASN1_OBJECT *pAVar7;
  uint length;
  uint *puVar8;
  int *piVar9;
  int iVar10;
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
  puVar1 = (uchar *)CONF_parse_list(str,0x2c,1,asn1_cb + 1,&local_1d0);
  inform = local_1c4;
  if (puVar1 != (uchar *)0x0) {
    return (ASN1_TYPE *)0x0;
  }
  if (local_1c8 - 0x10U < 2) {
    if (cnf == (X509V3_CTX *)0x0) {
      ERR_put_error(0xd,0xb2,0xc0,"asn1_gen.c",0xa3);
      return (ASN1_TYPE *)0x0;
    }
    local_1dc.section = (char *)puVar1;
    st = sk_new_null();
    if (st == (_STACK *)0x0) {
LAB_000c1492:
      a = (_STACK *)0x0;
      local_1c0 = a;
LAB_000c13c8:
      if ((uchar *)local_1dc.section != (uchar *)0x0) {
        CRYPTO_free(local_1dc.section);
      }
      if (st != (_STACK *)0x0) goto LAB_000c108e;
    }
    else {
      if (local_1c0 != (_STACK *)0x0) {
        local_1c0 = (_STACK *)X509V3_get_section(cnf,(char *)local_1c0);
        if (local_1c0 == (_STACK *)0x0) goto LAB_000c1492;
        do {
          iVar10 = sk_num(local_1c0);
          if (iVar10 <= (int)puVar1) goto LAB_000c104a;
          pvVar2 = sk_value(local_1c0,(int)puVar1);
          a = (_STACK *)ASN1_generate_v3(*(char **)((int)pvVar2 + 8),cnf);
        } while ((a != (_STACK *)0x0) &&
                (a = (_STACK *)sk_push(st,a), puVar1 = puVar1 + 1, a != (_STACK *)0x0));
        goto LAB_000c13c8;
      }
LAB_000c104a:
      if (local_1c8 == 0x11) {
        iVar10 = i2d_ASN1_SET_ANY((ASN1_SEQUENCE_ANY *)st,(uchar **)&local_1dc);
      }
      else {
        iVar10 = i2d_ASN1_SEQUENCE_ANY((ASN1_SEQUENCE_ANY *)st,(uchar **)&local_1dc);
      }
      if (iVar10 < 0) {
        a = (_STACK *)0x0;
        goto LAB_000c13c8;
      }
      a = (_STACK *)ASN1_TYPE_new();
      if (a == (_STACK *)0x0) goto LAB_000c13c8;
      pAVar3 = ASN1_STRING_type_new(local_1c8);
      a->data = (char **)pAVar3;
      if (pAVar3 == (ASN1_STRING *)0x0) goto LAB_000c13c8;
      a->num = local_1c8;
      pAVar3->length = iVar10;
      pAVar3->data = (uchar *)local_1dc.section;
      local_1dc.section = (char *)0x0;
LAB_000c108e:
      sk_pop_free(st,ASN1_TYPE_free);
    }
    inform = cnf;
    if (local_1c0 != (_STACK *)0x0) {
      X509V3_section_free(cnf,(stack_st_CONF_VALUE *)local_1c0);
    }
    goto LAB_000c10a6;
  }
  a = (_STACK *)ASN1_TYPE_new();
  if (a == (_STACK *)0x0) {
    ERR_put_error(0xd,0xb3,0x41,"asn1_gen.c",0x282);
    return (ASN1_TYPE *)0x0;
  }
  if (local_1c0 == (_STACK *)0x0) {
    local_1c0 = (_STACK *)0x12c180;
  }
  switch(local_1c8) {
  case 1:
    if (inform != (X509V3_CTX *)0x1) {
      ERR_put_error(0xd,0xb3,0xbe,"asn1_gen.c",0x297);
      goto LAB_000c13b0;
    }
    local_1dc.name = (char *)0x0;
    local_1dc.section = (char *)0x0;
    local_1dc.value = (char *)local_1c0;
    iVar10 = X509V3_get_value_bool(&local_1dc,&((_union_257 *)&a->data)->boolean);
    if (iVar10 != 0) goto LAB_000c1382;
    ERR_put_error(0xd,0xb3,0xb0,"asn1_gen.c",0x29f);
    break;
  case 2:
  case 10:
    if (inform != (X509V3_CTX *)0x1) {
      ERR_put_error(0xd,0xb3,0xb9,"asn1_gen.c",0x2a8);
      goto LAB_000c13b0;
    }
    pAVar6 = s2i_ASN1_INTEGER((X509V3_EXT_METHOD *)0x0,(char *)local_1c0);
    ((_union_257 *)&a->data)->integer = pAVar6;
    if (pAVar6 != (ASN1_INTEGER *)0x0) goto LAB_000c1382;
    ERR_put_error(0xd,0xb3,0xb4,"asn1_gen.c",0x2ad);
    break;
  case 3:
  case 4:
    pAVar3 = ASN1_STRING_new();
    ((_union_257 *)&a->data)->asn1_string = pAVar3;
    if (pAVar3 == (ASN1_STRING *)0x0) {
      ERR_put_error(0xd,0xb3,0x41,"asn1_gen.c",0x2fe);
      goto LAB_000c13b0;
    }
    if (inform == (X509V3_CTX *)0x3) {
      puVar1 = string_to_hex((char *)local_1c0,(long *)(local_1e4 + 1));
      if (puVar1 != (uchar *)0x0) {
        pAVar3 = ((_union_257 *)&a->data)->asn1_string;
        pAVar3->length = local_1e4[1];
        pAVar3->data = puVar1;
        pAVar3->type = local_1c8;
        goto LAB_000c145a;
      }
      ERR_put_error(0xd,0xb3,0xb2,"asn1_gen.c",0x307);
    }
    else {
      if (inform == (X509V3_CTX *)0x1) {
        ASN1_STRING_set(pAVar3,local_1c0,-1);
LAB_000c145a:
        if (local_1c8 == 3) {
          ((_union_257 *)&a->data)->asn1_string->flags =
               ((_union_257 *)&a->data)->asn1_string->flags & 0xfffffff0U | 8;
        }
        goto LAB_000c1382;
      }
      if (local_1c8 != 3 || inform != (X509V3_CTX *)&DAT_00000004) {
        ERR_put_error(0xd,0xb3,0xaf,"asn1_gen.c",0x31e);
        goto LAB_000c13b0;
      }
      iVar10 = CONF_parse_list((char *)local_1c0,0x2c,1,bitstr_cb + 1,pAVar3);
      if (iVar10 != 0) goto LAB_000c1382;
      ERR_put_error(0xd,0xb3,0xbc,"asn1_gen.c",0x316);
    }
    break;
  case 5:
    if (*(char *)&local_1c0->num != '\0') {
      ERR_put_error(0xd,0xb3,0xb6,"asn1_gen.c",0x28f);
      goto LAB_000c13b0;
    }
    goto LAB_000c1382;
  case 6:
    if (inform != (X509V3_CTX *)0x1) {
      ERR_put_error(0xd,0xb3,0xbf,"asn1_gen.c",0x2b5);
      goto LAB_000c13b0;
    }
    pAVar7 = OBJ_txt2obj((char *)local_1c0,0);
    ((_union_257 *)&a->data)->object = pAVar7;
    if (pAVar7 != (ASN1_OBJECT *)0x0) goto LAB_000c1382;
    ERR_put_error(0xd,0xb3,0xb7,"asn1_gen.c",0x2ba);
    break;
  default:
    ERR_put_error(0xd,0xb3,0xc4,"asn1_gen.c",0x32e);
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
        ERR_put_error(0xd,0xb3,0xb1,"asn1_gen.c",0x2e9);
        goto LAB_000c13b0;
      }
      inform = (X509V3_CTX *)0x1000;
    }
    mask = ASN1_tag2bit(local_1c8);
    iVar10 = ASN1_mbstring_copy(&((_union_257 *)&a->data)->asn1_string,(uchar *)local_1c0,-1,
                                (int)inform,mask);
    if (iVar10 < 1) {
      iVar10 = 0x2f1;
      goto LAB_000c133e;
    }
LAB_000c1382:
    a->num = local_1c8;
LAB_000c10a6:
    if (a == (_STACK *)0x0) {
      return (ASN1_TYPE *)0x0;
    }
    if ((local_1d0 == -1) && (local_2c == 0)) {
      return (ASN1_TYPE *)a;
    }
    puVar1 = (uchar *)i2d_ASN1_TYPE((ASN1_TYPE *)a,&local_1f4);
    ASN1_TYPE_free((ASN1_TYPE *)a);
    local_1f0 = local_1f4;
    if (local_1d0 == -1) {
      local_1fc = (X509V3_CTX *)0x0;
      num = puVar1;
LAB_000c111e:
      if (0 < local_2c) {
        puVar8 = local_1e4 + local_2c * 5;
        iVar10 = 0;
        do {
          iVar10 = iVar10 + 1;
          puVar8[9] = (uint)(num + puVar8[8]);
          num = (uchar *)ASN1_object_size(0,(int)(num + puVar8[8]),puVar8[5]);
          puVar8 = puVar8 + -5;
        } while (iVar10 < local_2c);
      }
      ptr = (uchar *)CRYPTO_malloc((int)num,"asn1_gen.c",0xe5);
      if (ptr != (uchar *)0x0) {
        local_1ec = ptr;
        if (0 < local_2c) {
          iVar10 = 0;
          piVar9 = aiStack_1bc;
          do {
            iVar10 = iVar10 + 1;
            ASN1_put_object(&local_1ec,piVar9[2],piVar9[4],*piVar9,piVar9[1]);
            if (piVar9[3] != 0) {
              *local_1ec = '\0';
              local_1ec = local_1ec + 1;
            }
            piVar9 = piVar9 + 5;
          } while (iVar10 < local_2c);
        }
        if (local_1d0 != -1) {
          if ((local_1cc == 0) && (local_1d0 - 0x10U < 2)) {
            local_1fc = (X509V3_CTX *)0x20;
          }
          ASN1_put_object(&local_1ec,(int)local_1fc,local_1e4[0],local_1d0,local_1cc);
        }
        memcpy(local_1ec,local_1f0,(size_t)puVar1);
        local_1e8 = ptr;
        pAVar5 = d2i_ASN1_TYPE((ASN1_TYPE **)0x0,&local_1e8,(long)num);
        goto LAB_000c11e8;
      }
    }
    else {
      pXVar4 = (X509V3_CTX *)
               ASN1_get_object(&local_1f0,(long *)local_1e4,(int *)(local_1e4 + 1),(int *)&local_1dc
                               ,(long)puVar1);
      length = (uint)pXVar4 & 0x80;
      if (length == 0) {
        bVar11 = -1 < (int)pXVar4 << 0x1f;
        if (bVar11) {
          pXVar4 = (X509V3_CTX *)((uint)pXVar4 & 0x20);
          length = local_1e4[0];
        }
        else {
          inform = (X509V3_CTX *)0x2;
        }
        if (bVar11) {
          local_1fc = pXVar4;
        }
        puVar1 = local_1f4 + ((int)puVar1 - (int)local_1f0);
        if (!bVar11) {
          local_1fc = inform;
          local_1e4[0] = length;
        }
        num = (uchar *)ASN1_object_size(0,length,local_1d0);
        goto LAB_000c111e;
      }
    }
    ptr = (uchar *)0x0;
    pAVar5 = (ASN1_TYPE *)0x0;
LAB_000c11e8:
    if (local_1f4 != (uchar *)0x0) {
      CRYPTO_free(local_1f4);
    }
    if (ptr != (uchar *)0x0) {
      CRYPTO_free(ptr);
    }
    return pAVar5;
  case 0x17:
  case 0x18:
    if (inform != (X509V3_CTX *)0x1) {
      ERR_put_error(0xd,0xb3,0xc1,"asn1_gen.c",0x2c3);
      goto LAB_000c13b0;
    }
    pAVar3 = ASN1_STRING_new();
    ((_union_257 *)&a->data)->asn1_string = pAVar3;
    if (pAVar3 == (ASN1_STRING *)0x0) {
      iVar10 = 0x2c8;
    }
    else {
      iVar10 = ASN1_STRING_set(pAVar3,local_1c0,-1);
      if (iVar10 != 0) {
        t = ((_union_257 *)&a->data)->asn1_string;
        t->type = local_1c8;
        iVar10 = ASN1_TIME_check(t);
        if (iVar10 != 0) goto LAB_000c1382;
        ERR_put_error(0xd,0xb3,0xb8,"asn1_gen.c",0x2d3);
        break;
      }
      iVar10 = 0x2cd;
    }
LAB_000c133e:
    ERR_put_error(0xd,0xb3,0x41,"asn1_gen.c",iVar10);
  }
  ERR_add_error_data(2,"string=",local_1c0);
LAB_000c13b0:
  ASN1_TYPE_free((ASN1_TYPE *)a);
  return (ASN1_TYPE *)0x0;
}

