
ASN1_STRING *
int_d2i_ASN1_bytes(ASN1_STRING **param_1,uchar **param_2,uchar *param_3,int param_4,int param_5,
                  int param_6,uint *param_7)

{
  uint uVar1;
  uint uVar2;
  ASN1_STRING *a;
  int iVar3;
  int iVar4;
  uchar *puVar5;
  uchar *puVar6;
  ASN1_STRING *a_00;
  ASN1_STRING *a_01;
  uchar *puVar7;
  uchar *__dest;
  int iVar8;
  uchar *local_bc;
  uchar *local_b8;
  int local_b4;
  int iStack_b0;
  uchar *local_ac;
  uchar *local_a8;
  int local_a4;
  int iStack_a0;
  ASN1_STRING *local_9c;
  BUF_MEM local_98;
  BUF_MEM local_8c;
  ASN1_const_CTX local_80;
  ASN1_const_CTX local_54;
  
  if (0x14 < param_6) {
    *param_7 = 0xc5;
    return (ASN1_STRING *)0x0;
  }
  if (((param_1 == (ASN1_STRING **)0x0) || (a_00 = *param_1, a_00 == (ASN1_STRING *)0x0)) &&
     (a_00 = ASN1_STRING_new(), a_00 == (ASN1_STRING *)0x0)) {
    return (ASN1_STRING *)0x0;
  }
  local_bc = *param_2;
  uVar1 = ASN1_get_object(&local_bc,(long *)&local_b8,&local_b4,&iStack_b0,(long)param_3);
  puVar7 = local_b8;
  if ((uVar1 & 0x80) == 0) {
    if (local_b4 == param_4) {
      if ((int)(uVar1 << 0x1a) < 0) {
        local_80.xclass = param_5;
        local_80.p = local_bc;
        local_80.slen = (long)local_b8;
        if (param_3 != (uchar *)0x0) {
          param_3 = param_3 + (int)local_bc;
        }
        uVar2 = uVar1 & 1;
        iVar8 = 0;
        local_98.length = 0;
        local_98.max = 0;
        local_98.data = (char *)0x0;
        a_01 = (ASN1_STRING *)0x0;
        local_80.error = uVar1 & 0x80;
        local_80.inf = uVar1;
        local_80.tag = param_4;
        local_80.max = param_3;
        local_80.pp = param_2;
        do {
          if (uVar2 != 0) {
            local_80.eos = ASN1_const_check_infinite_end
                                     (&local_80.p,(int)local_80.max - (int)local_80.p);
            if (local_80.eos == 0) goto LAB_0010fc98;
LAB_0010fd24:
            iVar3 = asn1_const_Finish(&local_80);
            if (iVar3 != 0) {
              a_00->length = iVar8;
              if (a_00->data != (uchar *)0x0) {
                CRYPTO_free(a_00->data);
              }
              a_00->data = (uchar *)local_98.data;
              if (a_01 != (ASN1_STRING *)0x0) {
                ASN1_STRING_free(a_01);
              }
              goto LAB_0010fd48;
            }
LAB_0010fce4:
            a = a_01;
            if (a_01 == (ASN1_STRING *)0x0) goto LAB_0010fcec;
            goto LAB_0010fce6;
          }
          if (local_80.slen < 1) goto LAB_0010fd24;
LAB_0010fc98:
          iVar4 = local_80.xclass;
          iVar3 = local_80.tag;
          local_80.q = local_80.p;
          puVar7 = local_80.max + -(int)local_80.p;
          if (param_6 == 0x14) {
            local_80.error = 0xc5;
            goto LAB_0010fce4;
          }
          a = a_01;
          if ((a_01 == (ASN1_STRING *)0x0) && (a = ASN1_STRING_new(), a == (ASN1_STRING *)0x0))
          goto LAB_0010fcec;
          local_ac = local_80.p;
          uVar1 = ASN1_get_object(&local_ac,(long *)&local_a8,&local_a4,&iStack_a0,(long)puVar7);
          puVar5 = local_a8;
          uVar2 = uVar1 & 0x80;
          if (uVar2 != 0) {
            local_80.error = 0x66;
LAB_0010fcda:
            if (a != a_01) {
              ASN1_STRING_free(a);
            }
            goto LAB_0010fce4;
          }
          if (iVar3 != local_a4) {
            local_80.error = 0xa8;
            goto LAB_0010fcda;
          }
          if ((int)(uVar1 << 0x1a) < 0) {
            local_54.pp = (uchar **)&local_80;
            local_54.p = local_ac;
            local_54.tag = iVar3;
            local_54.xclass = iVar4;
            local_54.slen = (long)local_a8;
            local_54.max = local_ac + (int)puVar7;
            if (puVar7 == (uchar *)0x0) {
              local_54.max = puVar7;
            }
            iVar3 = 0;
            local_9c = (ASN1_STRING *)0x0;
            local_8c.length = 0;
            local_8c.max = 0;
            local_8c.data = (char *)0x0;
            local_54.error = uVar2;
            local_54.inf = uVar1;
            if ((uVar1 & 1) != 0) goto LAB_0010feca;
            while (0 < local_54.slen) {
              while( true ) {
                local_54.q = local_54.p;
                iVar4 = int_d2i_ASN1_bytes(&local_9c,&local_54,(int)local_54.max - (int)local_54.p,
                                           local_54.tag,local_54.xclass,param_6 + 2,&local_54.error)
                ;
                if (iVar4 == 0) goto LAB_0010ff40;
                iVar4 = BUF_MEM_grow_clean(&local_8c,local_9c->length + iVar3);
                if (iVar4 == 0) {
                  local_54.error = 7;
                  goto LAB_0010ff40;
                }
                memcpy(local_8c.data + iVar3,local_9c->data,local_9c->length);
                if ((local_54.inf & 1U) == 0) {
                  local_54.slen = local_54.slen + ((int)local_54.q - (int)local_54.p);
                }
                iVar3 = iVar3 + local_9c->length;
                if ((local_54.inf & 1U) == 0) break;
LAB_0010feca:
                local_54.eos = ASN1_const_check_infinite_end
                                         (&local_54.p,(int)local_54.max - (int)local_54.p);
                if (local_54.eos != 0) goto LAB_0010fedc;
              }
            }
LAB_0010fedc:
            iVar4 = asn1_const_Finish(&local_54);
            if (iVar4 == 0) {
LAB_0010ff40:
              if (local_9c != (ASN1_STRING *)0x0) {
                ASN1_STRING_free(local_9c);
              }
              if ((uchar *)local_8c.data != (uchar *)0x0) {
                CRYPTO_free(local_8c.data);
              }
              local_80.error = local_54.error;
              goto LAB_0010fcda;
            }
            a->length = iVar3;
            if (a->data != (uchar *)0x0) {
              CRYPTO_free(a->data);
            }
            a->data = (uchar *)local_8c.data;
            if (local_9c != (ASN1_STRING *)0x0) {
              ASN1_STRING_free(local_9c);
            }
            puVar7 = (uchar *)a->length;
            local_80.p = local_54.p;
          }
          else {
            if (local_a8 == (uchar *)0x0) {
              puVar7 = a->data;
              puVar6 = local_ac;
              __dest = puVar7;
              if (puVar7 != (uchar *)0x0) {
                CRYPTO_free(puVar7);
                puVar7 = local_a8;
                puVar6 = local_ac;
                __dest = puVar5;
              }
            }
            else {
              if ((a->length < (int)local_a8) || (__dest = a->data, __dest == (uchar *)0x0)) {
                __dest = (uchar *)CRYPTO_malloc((int)(local_a8 + 1),"a_bytes.c",0xe9);
                if (__dest == (uchar *)0x0) {
                  local_80.error = 0x41;
                  goto LAB_0010fcda;
                }
                if (a->data != (uchar *)0x0) {
                  CRYPTO_free(a->data);
                }
              }
              memcpy(__dest,local_ac,(size_t)local_a8);
              __dest[(int)local_a8] = '\0';
              puVar7 = local_a8;
              puVar6 = local_a8 + (int)local_ac;
            }
            a->length = (int)puVar7;
            a->type = iVar3;
            a->data = __dest;
            local_80.p = puVar6;
          }
          iVar3 = BUF_MEM_grow_clean(&local_98,(size_t)(puVar7 + iVar8));
          if (iVar3 == 0) goto LAB_0010ffca;
          memcpy(local_98.data + iVar8,a->data,a->length);
          uVar2 = local_80.inf & 1;
          if (uVar2 == 0) {
            local_80.slen = local_80.slen + ((int)local_80.q - (int)local_80.p);
          }
          iVar8 = iVar8 + a->length;
          a_01 = a;
        } while( true );
      }
      if (local_b8 == (uchar *)0x0) {
        puVar5 = a_00->data;
        local_80.p = local_bc;
        puVar6 = puVar5;
        if (puVar5 != (uchar *)0x0) {
          CRYPTO_free(puVar5);
          puVar5 = local_b8;
          local_80.p = local_bc;
          puVar6 = puVar7;
        }
      }
      else {
        if ((a_00->length < (int)local_b8) || (puVar6 = a_00->data, puVar6 == (uchar *)0x0)) {
          puVar6 = (uchar *)CRYPTO_malloc((int)(local_b8 + 1),"a_bytes.c",0xe9);
          if (puVar6 == (uchar *)0x0) {
            *param_7 = 0x41;
            goto LAB_0010fc2a;
          }
          if (a_00->data != (uchar *)0x0) {
            CRYPTO_free(a_00->data);
          }
        }
        memcpy(puVar6,local_bc,(size_t)local_b8);
        puVar6[(int)local_b8] = '\0';
        local_80.p = local_b8 + (int)local_bc;
        puVar5 = local_b8;
      }
      a_00->length = (int)puVar5;
      a_00->data = puVar6;
      a_00->type = local_b4;
LAB_0010fd48:
      if (param_1 != (ASN1_STRING **)0x0) {
        *param_1 = a_00;
      }
      *param_2 = local_80.p;
      return a_00;
    }
    *param_7 = 0xa8;
  }
  else {
    *param_7 = 0x66;
  }
  goto LAB_0010fc2a;
LAB_0010ffca:
  local_80.error = 7;
LAB_0010fce6:
  ASN1_STRING_free(a);
LAB_0010fcec:
  if ((uchar *)local_98.data != (uchar *)0x0) {
    CRYPTO_free(local_98.data);
  }
  *param_7 = local_80.error;
LAB_0010fc2a:
  if ((param_1 == (ASN1_STRING **)0x0) || (*param_1 != a_00)) {
    ASN1_STRING_free(a_00);
  }
  return (ASN1_STRING *)0x0;
}

