
void asn1_parse2(BIO *param_1,byte **param_2,int param_3,int param_4,int param_5,int param_6,
                ASN1_STRING *param_7)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  ASN1_OBJECT *pAVar5;
  ASN1_OCTET_STRING *a;
  char *data;
  byte *pbVar6;
  ASN1_STRING *pAVar7;
  byte *pbVar8;
  ASN1_STRING *pAVar9;
  int iVar10;
  byte *pbVar11;
  byte *pbVar12;
  int local_e8;
  char *local_e0;
  byte *local_c4;
  byte *local_c0;
  int local_bc;
  uint local_b8;
  ASN1_STRING *local_b4;
  ASN1_OBJECT *local_b0;
  char acStack_ac [128];
  int local_2c;
  
  local_c4 = *param_2;
  pbVar8 = local_c4 + param_3;
  local_2c = __TMC_END__;
  local_b0 = (ASN1_OBJECT *)0x0;
  if (local_c4 < pbVar8) {
    local_e0 = "prim: ";
    local_e8 = param_3;
LAB_000c15e0:
    pbVar12 = local_c4;
    uVar2 = ASN1_get_object(&local_c4,&local_bc,(int *)&local_b8,(int *)&local_b4,local_e8);
    if ((uVar2 & 0x80) == 0) {
      iVar10 = (int)local_c4 - (int)pbVar12;
      iVar3 = BIO_printf(param_1,"%5ld:",pbVar12 + (param_4 - (int)*param_2));
      if (iVar3 < 1) goto LAB_000c1664;
      if (uVar2 == 0x21) {
        iVar3 = BIO_printf(param_1,"d=%-2d hl=%ld l=inf  ",param_5,iVar10);
        if (0 < iVar3) goto LAB_000c1638;
        goto LAB_000c1664;
      }
      iVar3 = BIO_printf(param_1,"d=%-2d hl=%ld l=%4ld ",param_5,iVar10,local_bc);
      if (iVar3 < 1) goto LAB_000c1664;
LAB_000c1638:
      pAVar7 = local_b4;
      uVar1 = local_b8;
      iVar3 = param_5;
      if (param_6 == 0) {
        iVar3 = 0;
      }
      pAVar9 = (ASN1_STRING *)(uVar2 & 0x20);
      data = local_e0;
      if (pAVar9 != (ASN1_STRING *)0x0) {
        data = "cons: ";
      }
      iVar4 = BIO_write(param_1,data,6);
      if (iVar4 < 6) goto LAB_000c1664;
      BIO_indent(param_1,iVar3,0x80);
      if (((uint)pAVar7 & 0xc0) == 0xc0) {
        BIO_snprintf(acStack_ac,0x80,"priv [ %d ] ",uVar1);
      }
      else if (((uint)pAVar7 & 0x80) == 0) {
        if (((uint)pAVar7 & 0x40) == 0) {
          if (0x1e < (int)uVar1) {
            BIO_snprintf(acStack_ac,0x80,"<ASN1 %d>",uVar1);
          }
        }
        else {
          BIO_snprintf(acStack_ac,0x80,"appl [ %d ]",uVar1);
        }
      }
      else {
        BIO_snprintf(acStack_ac,0x80,"cont [ %d ]",uVar1);
      }
      iVar3 = BIO_printf(param_1,PTR_fmt_9793_000c19b8);
      if (iVar3 < 1) goto LAB_000c1664;
      local_e8 = local_e8 - iVar10;
      if (pAVar9 == (ASN1_STRING *)0x0) {
        if (local_b4 == (ASN1_STRING *)0x0) {
          if ((((local_b8 - 0x16 < 3) || (local_b8 == 0x1a)) || (local_b8 - 0x12 < 3)) ||
             (local_b8 == 0xc)) {
            iVar3 = BIO_write(param_1,":",1);
            if ((iVar3 < 1) ||
               ((0 < local_bc && (iVar3 = BIO_write(param_1,local_c4,local_bc), iVar3 != local_bc)))
               ) goto LAB_000c1664;
            goto LAB_000c17a6;
          }
          if (local_b8 == 6) {
            local_c0 = pbVar12;
            pAVar5 = d2i_ASN1_OBJECT(&local_b0,&local_c0,local_bc + iVar10);
            if (pAVar5 == (ASN1_OBJECT *)0x0) {
              iVar3 = BIO_write(param_1,":BAD OBJECT",0xb);
              if (0 < iVar3) goto LAB_000c17a6;
            }
            else {
              iVar3 = BIO_write(param_1,":",1);
              if (0 < iVar3) {
                i2a_ASN1_OBJECT(param_1,local_b0);
                goto LAB_000c17a6;
              }
            }
            goto LAB_000c1664;
          }
          if (local_b8 == 1) {
            local_c0 = pbVar12;
            iVar3 = d2i_ASN1_BOOLEAN((int *)0x0,&local_c0,local_bc + iVar10);
            if ((iVar3 < 0) && (iVar10 = BIO_write(param_1,"Bad boolean\n",0xc), iVar10 < 1))
            goto LAB_000c1664;
            BIO_printf(param_1,":%d",iVar3);
            goto LAB_000c17a6;
          }
          if (local_b8 == 0x1e) goto LAB_000c17a6;
          if (local_b8 == 4) {
            local_c0 = pbVar12;
            a = d2i_ASN1_OCTET_STRING((ASN1_OCTET_STRING **)0x0,&local_c0,local_bc + iVar10);
            if (a == (ASN1_OCTET_STRING *)0x0) goto LAB_000c17a6;
            if (0 < a->length) {
              local_c0 = a->data;
              pbVar11 = local_c0;
              do {
                pbVar6 = pbVar11 + 1;
                uVar2 = (uint)*pbVar11;
                iVar3 = uVar2 - 10;
                if (iVar3 != 0) {
                  iVar3 = 1;
                }
                if (0x1f < uVar2) {
                  iVar3 = 0;
                }
                if (iVar3 == 0) {
                  if (0x7e < uVar2) {
LAB_000c1a2c:
                    if (param_7 == (ASN1_STRING *)0x0) {
                      iVar3 = BIO_write(param_1,"[HEX DUMP]:",0xb);
                      pAVar9 = param_7;
                      pAVar7 = a;
                      if (iVar3 < 1) goto LAB_000c166a;
                      if (0 < a->length) goto LAB_000c1a64;
                      goto LAB_000c1a84;
                    }
                    iVar3 = BIO_write(param_1,"\n",1);
                    if (iVar3 < 1) goto LAB_000c1a7a;
                    if (param_7 == (ASN1_STRING *)0xffffffff) {
                      pAVar9 = (ASN1_STRING *)a->length;
LAB_000c1c3a:
                      pAVar7 = pAVar9;
                    }
                    else {
                      pAVar7 = param_7;
                      pAVar9 = (ASN1_STRING *)a->length;
                      if ((int)(ASN1_STRING *)a->length < (int)param_7) goto LAB_000c1c3a;
                    }
                    iVar3 = BIO_dump_indent(param_1,local_c0,pAVar7,6);
                    if (iVar3 < 1) goto LAB_000c1a7a;
                    ASN1_STRING_free(a);
                    goto LAB_000c17bc;
                  }
                }
                else if ((uVar2 & 0xfb) != 9) goto LAB_000c1a2c;
                pbVar11 = pbVar6;
              } while (pbVar6 != local_c0 + a->length);
              iVar3 = BIO_write(param_1,":",1);
              if ((iVar3 < 1) || (iVar3 = BIO_write(param_1,local_c0,a->length), iVar3 < 1))
              goto LAB_000c1a7a;
            }
            goto LAB_000c1a84;
          }
          if (local_b8 != 2) {
            if (local_b8 == 10) {
              local_c0 = pbVar12;
              a = d2i_ASN1_ENUMERATED((ASN1_ENUMERATED **)0x0,&local_c0,local_bc + iVar10);
              if (a == (ASN1_ENUMERATED *)0x0) {
                iVar3 = BIO_write(param_1,"BAD ENUMERATED",0xb);
                goto joined_r0x000c1c80;
              }
              iVar3 = BIO_write(param_1,":",1);
              if ((0 < iVar3) &&
                 ((a->type != 0x10a || (iVar3 = BIO_write(param_1,&DAT_001591bc,1), 0 < iVar3)))) {
                pAVar9 = (ASN1_STRING *)a->length;
                if (0 < (int)pAVar9) {
                  iVar3 = 0;
                  do {
                    iVar10 = BIO_printf(param_1,"%02X",(uint)a->data[iVar3]);
                    if (iVar10 < 1) goto LAB_000c1664;
                    pAVar9 = (ASN1_STRING *)a->length;
                    iVar3 = iVar3 + 1;
                  } while (iVar3 < (int)pAVar9);
                }
                goto LAB_000c1b02;
              }
              goto LAB_000c1664;
            }
            if ((local_bc < 1) || (param_7 == (ASN1_STRING *)0x0)) goto LAB_000c17a6;
            iVar3 = BIO_write(param_1,"\n",1);
            if (iVar3 < 1) goto LAB_000c1664;
            iVar3 = BIO_dump_indent(param_1,local_c4);
            goto joined_r0x000c176c;
          }
          local_c0 = pbVar12;
          a = d2i_ASN1_INTEGER((ASN1_INTEGER **)0x0,&local_c0,local_bc + iVar10);
          if (a == (ASN1_INTEGER *)0x0) {
            iVar3 = BIO_write(param_1,"BAD INTEGER",0xb);
joined_r0x000c1c80:
            if (0 < iVar3) goto LAB_000c1a84;
LAB_000c1a7a:
            pAVar9 = (ASN1_STRING *)0x0;
            pAVar7 = a;
          }
          else {
            iVar3 = BIO_write(param_1,":",1);
            if ((iVar3 < 1) ||
               ((a->type == 0x102 && (iVar3 = BIO_write(param_1,&DAT_001591bc,1), iVar3 < 1))))
            goto LAB_000c1664;
            pAVar9 = (ASN1_STRING *)a->length;
            if (0 < (int)pAVar9) {
              iVar3 = 0;
              do {
                iVar10 = BIO_printf(param_1,"%02X",(uint)a->data[iVar3]);
                if (iVar10 < 1) goto LAB_000c1664;
                pAVar9 = (ASN1_STRING *)a->length;
                iVar3 = iVar3 + 1;
              } while (iVar3 < (int)pAVar9);
            }
LAB_000c1b02:
            if ((pAVar9 != (ASN1_STRING *)0x0) ||
               (iVar3 = BIO_write(param_1,"00",2), pAVar7 = pAVar9, 0 < iVar3)) goto LAB_000c1a84;
          }
        }
        else {
          local_c4 = local_c4 + local_bc;
          iVar3 = BIO_write(param_1,"\n",1);
          pAVar7 = pAVar9;
          if (0 < iVar3) goto LAB_000c17d0;
        }
      }
      else {
        pbVar11 = local_c4 + local_bc;
        iVar3 = BIO_write(param_1,"\n",1);
        if (iVar3 < 1) goto LAB_000c1664;
        if (local_bc <= local_e8) {
          if ((uVar2 == 0x21) && (local_bc == 0)) {
            while( true ) {
              pAVar9 = (ASN1_STRING *)
                       asn1_parse2(param_1,&local_c4,(int)pbVar8 - (int)local_c4,
                                   local_c4 + (param_4 - (int)*param_2),param_5 + 1,param_6,param_7)
              ;
              pAVar7 = pAVar9;
              if (pAVar9 == (ASN1_STRING *)0x0) goto LAB_000c166a;
              if (pAVar9 == (ASN1_STRING *)0x2) break;
              if (pbVar8 <= local_c4) goto LAB_000c1944;
            }
          }
          else {
            while (local_c4 < pbVar11) {
              pAVar9 = (ASN1_STRING *)
                       asn1_parse2(param_1,&local_c4,local_bc,local_c4 + (param_4 - (int)*param_2),
                                   param_5 + 1,param_6,param_7);
              pAVar7 = pAVar9;
              if (pAVar9 == (ASN1_STRING *)0x0) goto LAB_000c166a;
            }
          }
          goto LAB_000c17d0;
        }
        BIO_printf(param_1,"length is greater than %ld\n",local_e8);
        pAVar9 = (ASN1_STRING *)0x0;
        pAVar7 = (ASN1_STRING *)0x0;
      }
    }
    else {
      BIO_write(param_1,"Error in encoding\n",0x12);
      pAVar9 = (ASN1_STRING *)0x0;
      pAVar7 = (ASN1_STRING *)0x0;
    }
    goto LAB_000c166a;
  }
  pAVar9 = (ASN1_STRING *)0x1;
LAB_000c1678:
  *param_2 = local_c4;
  if (local_2c == __TMC_END__) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(pAVar9);
  while (pAVar9 = (ASN1_STRING *)((int)&pAVar9->length + 1), (int)pAVar9 < a->length) {
LAB_000c1a64:
    iVar3 = BIO_printf(param_1,"%02X",(uint)local_c0[(int)pAVar9]);
    if (iVar3 < 1) goto LAB_000c1a7a;
  }
LAB_000c1a84:
  ASN1_STRING_free(a);
LAB_000c17a6:
  iVar3 = BIO_write(param_1,"\n",1);
joined_r0x000c176c:
  if (iVar3 < 1) {
LAB_000c1664:
    pAVar9 = (ASN1_STRING *)0x0;
    pAVar7 = (ASN1_STRING *)0x0;
    goto LAB_000c166a;
  }
LAB_000c17bc:
  local_c4 = local_c4 + local_bc;
  if ((local_b8 == 0) && (local_b4 == (ASN1_STRING *)0x0)) {
    pAVar9 = (ASN1_STRING *)0x2;
    pAVar7 = local_b4;
    goto LAB_000c166a;
  }
LAB_000c17d0:
  local_e8 = local_e8 - local_bc;
  if (pbVar8 <= local_c4 || local_c4 <= pbVar12) goto LAB_000c1944;
  goto LAB_000c15e0;
LAB_000c1944:
  pAVar9 = (ASN1_STRING *)0x1;
  pAVar7 = (ASN1_STRING *)0x0;
LAB_000c166a:
  if (local_b0 != (ASN1_OBJECT *)0x0) {
    ASN1_OBJECT_free(local_b0);
  }
  if (pAVar7 != (ASN1_STRING *)0x0) {
    ASN1_STRING_free(pAVar7);
  }
  goto LAB_000c1678;
}

