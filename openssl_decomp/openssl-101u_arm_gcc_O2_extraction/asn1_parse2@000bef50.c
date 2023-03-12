
void asn1_parse2(BIO *param_1,byte **param_2,int param_3,int param_4,int param_5,int param_6,
                ASN1_STRING *param_7)

{
  uint uVar1;
  byte *pbVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  byte *pbVar6;
  ASN1_OBJECT *pAVar7;
  ASN1_INTEGER *a;
  char *data;
  byte *pbVar8;
  byte *pbVar9;
  ASN1_STRING *pAVar10;
  ASN1_STRING *pAVar11;
  int iVar12;
  ASN1_STRING *a_00;
  byte *pbVar13;
  int local_e8;
  char *local_e0;
  byte *local_c4;
  byte *local_c0;
  byte *local_bc;
  uint local_b8;
  ASN1_STRING *local_b4;
  ASN1_OBJECT *local_b0;
  char acStack_ac [128];
  int local_2c;
  
  local_2c = __stack_chk_guard;
  local_b0 = (ASN1_OBJECT *)0x0;
  if (0x80 < param_5) {
    BIO_puts(param_1,"BAD RECURSION DEPTH\n");
    pAVar11 = (ASN1_STRING *)0x0;
    goto LAB_000bf046;
  }
  local_c4 = *param_2;
  pbVar8 = local_c4 + param_3;
  if (local_c4 < pbVar8) {
    local_e0 = "prim: ";
    local_e8 = param_3;
LAB_000befa4:
    pbVar13 = local_c4;
    uVar3 = ASN1_get_object(&local_c4,(long *)&local_bc,(int *)&local_b8,(int *)&local_b4,local_e8);
    a_00 = (ASN1_STRING *)(uVar3 & 0x80);
    if (a_00 != (ASN1_STRING *)0x0) {
      a_00 = (ASN1_STRING *)0x0;
      BIO_write(param_1,"Error in encoding\n",0x12);
      pAVar11 = (ASN1_STRING *)0x0;
      goto LAB_000bf032;
    }
    iVar12 = (int)local_c4 - (int)pbVar13;
    iVar4 = BIO_printf(param_1,"%5ld:",pbVar13 + (param_4 - (int)*param_2));
    pAVar11 = a_00;
    if (iVar4 < 1) goto LAB_000bf032;
    if (uVar3 == 0x21) {
      iVar4 = BIO_printf(param_1,"d=%-2d hl=%ld l=inf  ",param_5,iVar12);
      uVar1 = local_b8;
      pAVar10 = local_b4;
    }
    else {
      iVar4 = BIO_printf(param_1,"d=%-2d hl=%ld l=%4ld ",param_5,iVar12,local_bc);
      uVar1 = local_b8;
      pAVar10 = local_b4;
    }
    if (iVar4 < 1) goto LAB_000bf032;
    iVar4 = param_5;
    if (param_6 == 0) {
      iVar4 = 0;
    }
    a_00 = (ASN1_STRING *)(uVar3 & 0x20);
    data = local_e0;
    if (a_00 != (ASN1_STRING *)0x0) {
      data = "cons: ";
    }
    local_b8 = uVar1;
    local_b4 = pAVar10;
    iVar5 = BIO_write(param_1,data,6);
    if (iVar5 < 6) goto LAB_000bf02c;
    BIO_indent(param_1,iVar4,0x80);
    if (((uint)pAVar10 & 0xc0) == 0xc0) {
      BIO_snprintf(acStack_ac,0x80,"priv [ %d ] ",uVar1);
    }
    else if (((uint)pAVar10 & 0x80) == 0) {
      if (((uint)pAVar10 & 0x40) == 0) {
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
    iVar4 = BIO_printf(param_1,PTR_fmt_9800_000bf390);
    if (iVar4 < 1) goto LAB_000bf02c;
    local_e8 = local_e8 - iVar12;
    if (a_00 != (ASN1_STRING *)0x0) {
      pbVar9 = local_c4 + (int)local_bc;
      iVar4 = BIO_write(param_1,"\n",1);
      pbVar6 = local_c4;
      if (iVar4 < 1) goto LAB_000bf02c;
      if ((int)local_bc <= local_e8) {
        if ((uVar3 == 0x21) && (local_bc == (byte *)0x0)) {
          do {
            a_00 = (ASN1_STRING *)
                   asn1_parse2(param_1,&local_c4,(int)pbVar8 - (int)local_c4,
                               local_c4 + (param_4 - (int)*param_2),param_5 + 1,param_6,param_7);
            pAVar11 = a_00;
            if (a_00 == (ASN1_STRING *)0x0) goto LAB_000bf032;
          } while ((a_00 != (ASN1_STRING *)0x2) && (local_c4 < pbVar8));
          local_bc = local_c4 + -(int)pbVar6;
        }
        else if (local_c4 < pbVar9) {
          pbVar6 = local_bc;
          do {
            pbVar2 = local_c4;
            a_00 = (ASN1_STRING *)
                   asn1_parse2(param_1,&local_c4,pbVar6,local_c4 + (param_4 - (int)*param_2),
                               param_5 + 1,param_6,param_7);
            pAVar11 = a_00;
            if (a_00 == (ASN1_STRING *)0x0) goto LAB_000bf032;
            pbVar6 = pbVar2 + ((int)pbVar6 - (int)local_c4);
          } while (local_c4 < pbVar9);
        }
        goto LAB_000bf1b6;
      }
      a_00 = (ASN1_STRING *)0x0;
      BIO_printf(param_1,"length is greater than %ld\n",local_e8);
      pAVar11 = (ASN1_STRING *)0x0;
      goto LAB_000bf032;
    }
    if (local_b4 != (ASN1_STRING *)0x0) {
      local_c4 = local_c4 + (int)local_bc;
      iVar4 = BIO_write(param_1,"\n",1);
      pAVar11 = a_00;
      if (0 < iVar4) goto LAB_000bf1b6;
      goto LAB_000bf032;
    }
    if ((((local_b8 - 0x16 < 3) || (local_b8 == 0x1a)) || (local_b8 - 0x12 < 3)) ||
       (local_b8 == 0xc)) {
      iVar4 = BIO_write(param_1,":",1);
      if ((iVar4 < 1) ||
         ((0 < (int)local_bc &&
          (pbVar6 = (byte *)BIO_write(param_1,local_c4,(int)local_bc), pbVar6 != local_bc))))
      goto LAB_000bf02c;
      goto LAB_000bf18c;
    }
    if (local_b8 == 6) {
      local_c0 = pbVar13;
      pAVar7 = d2i_ASN1_OBJECT(&local_b0,&local_c0,(long)(local_bc + iVar12));
      if (pAVar7 == (ASN1_OBJECT *)0x0) {
        iVar4 = BIO_write(param_1,":BAD OBJECT",0xb);
        if (0 < iVar4) goto LAB_000bf18c;
      }
      else {
        iVar4 = BIO_write(param_1,":",1);
        if (0 < iVar4) {
          i2a_ASN1_OBJECT(param_1,local_b0);
          goto LAB_000bf18c;
        }
      }
      goto LAB_000bf02c;
    }
    if (local_b8 == 1) {
      local_c0 = pbVar13;
      iVar4 = d2i_ASN1_BOOLEAN((int *)0x0,&local_c0,(long)(local_bc + iVar12));
      if ((iVar4 < 0) && (iVar12 = BIO_write(param_1,"Bad boolean\n",0xc), iVar12 < 1))
      goto LAB_000bf02c;
      BIO_printf(param_1,":%d",iVar4);
      goto LAB_000bf18c;
    }
    if (local_b8 == 0x1e) goto LAB_000bf18c;
    if (local_b8 != 4) {
      if (local_b8 == 2) {
        local_c0 = pbVar13;
        a = d2i_ASN1_INTEGER((ASN1_INTEGER **)0x0,&local_c0,(long)(local_bc + iVar12));
        if (a == (ASN1_INTEGER *)0x0) {
          iVar4 = BIO_write(param_1,"BAD INTEGER",0xb);
          goto joined_r0x000bf680;
        }
        iVar4 = BIO_write(param_1,":",1);
        if ((iVar4 < 1) ||
           ((a->type == 0x102 && (iVar4 = BIO_write(param_1,&DAT_00157d4c,1), iVar4 < 1))))
        goto LAB_000bf02c;
        a_00 = (ASN1_STRING *)a->length;
        if (0 < (int)a_00) {
          iVar4 = 0;
          do {
            iVar12 = BIO_printf(param_1,"%02X",(uint)a->data[iVar4]);
            if (iVar12 < 1) goto LAB_000bf02c;
            a_00 = (ASN1_STRING *)a->length;
            iVar4 = iVar4 + 1;
          } while (iVar4 < (int)a_00);
        }
LAB_000bf4ec:
        if ((a_00 == (ASN1_OCTET_STRING *)0x0) && (iVar4 = BIO_write(param_1,"00",2), iVar4 < 1))
        goto LAB_000bf474;
LAB_000bf4f2:
        ASN1_STRING_free(a);
        goto LAB_000bf18c;
      }
      if (local_b8 == 10) {
        local_c0 = pbVar13;
        a = d2i_ASN1_ENUMERATED((ASN1_ENUMERATED **)0x0,&local_c0,(long)(local_bc + iVar12));
        if (a != (ASN1_ENUMERATED *)0x0) {
          iVar4 = BIO_write(param_1,":",1);
          if ((0 < iVar4) &&
             ((a->type != 0x10a || (iVar4 = BIO_write(param_1,&DAT_00157d4c,1), 0 < iVar4)))) {
            a_00 = (ASN1_STRING *)a->length;
            if (0 < (int)a_00) {
              iVar4 = 0;
              do {
                iVar12 = BIO_printf(param_1,"%02X",(uint)a->data[iVar4]);
                if (iVar12 < 1) goto LAB_000bf02c;
                a_00 = (ASN1_STRING *)a->length;
                iVar4 = iVar4 + 1;
              } while (iVar4 < (int)a_00);
            }
            goto LAB_000bf4ec;
          }
          goto LAB_000bf02c;
        }
        iVar4 = BIO_write(param_1,"BAD ENUMERATED",0xe);
joined_r0x000bf680:
        if (iVar4 < 1) goto LAB_000bf02c;
        goto LAB_000bf4f2;
      }
      if (((int)local_bc < 1) || (param_7 == (ASN1_STRING *)0x0)) goto LAB_000bf18c;
      iVar4 = BIO_write(param_1,"\n",1);
      if (iVar4 < 1) goto LAB_000bf02c;
      iVar4 = BIO_dump_indent(param_1,local_c4);
      goto joined_r0x000bf136;
    }
    local_c0 = pbVar13;
    a_00 = d2i_ASN1_OCTET_STRING((ASN1_OCTET_STRING **)0x0,&local_c0,(long)(local_bc + iVar12));
    if (a_00 == (ASN1_OCTET_STRING *)0x0) goto LAB_000bf18c;
    if (0 < a_00->length) {
      local_c0 = a_00->data;
      pbVar6 = local_c0;
      do {
        pbVar9 = pbVar6 + 1;
        uVar3 = (uint)*pbVar6;
        iVar4 = uVar3 - 10;
        if (iVar4 != 0) {
          iVar4 = 1;
        }
        if (0x1f < uVar3) {
          iVar4 = 0;
        }
        if (iVar4 == 0) {
          if (0x7e < uVar3) {
LAB_000bf42a:
            if (param_7 == (ASN1_STRING *)0x0) {
              iVar4 = BIO_write(param_1,"[HEX DUMP]:",0xb);
              pAVar11 = param_7;
              if (iVar4 < 1) goto LAB_000bf032;
              if (a_00->length < 1) goto LAB_000bf592;
              goto LAB_000bf45e;
            }
            iVar4 = BIO_write(param_1,"\n",1);
            if (iVar4 < 1) goto LAB_000bf474;
            if (param_7 == (ASN1_STRING *)0xffffffff) {
              pAVar11 = (ASN1_STRING *)a_00->length;
LAB_000bf60a:
              pAVar10 = pAVar11;
            }
            else {
              pAVar10 = param_7;
              pAVar11 = (ASN1_STRING *)a_00->length;
              if ((int)(ASN1_STRING *)a_00->length < (int)param_7) goto LAB_000bf60a;
            }
            iVar4 = BIO_dump_indent(param_1,local_c0,pAVar10,6);
            if (iVar4 < 1) goto LAB_000bf474;
            ASN1_STRING_free(a_00);
            goto LAB_000bf1a2;
          }
        }
        else if ((uVar3 & 0xfb) != 9) goto LAB_000bf42a;
        pbVar6 = pbVar9;
      } while (pbVar9 != local_c0 + a_00->length);
      iVar4 = BIO_write(param_1,":",1);
      if ((0 < iVar4) && (iVar4 = BIO_write(param_1,local_c0,a_00->length), 0 < iVar4))
      goto LAB_000bf592;
LAB_000bf474:
      pAVar11 = (ASN1_STRING *)0x0;
      goto LAB_000bf032;
    }
    goto LAB_000bf592;
  }
  pAVar11 = (ASN1_STRING *)0x1;
  goto LAB_000bf040;
  while (pAVar11 = (ASN1_STRING *)((int)&pAVar11->length + 1), (int)pAVar11 < a_00->length) {
LAB_000bf45e:
    iVar4 = BIO_printf(param_1,"%02X",(uint)local_c0[(int)pAVar11]);
    if (iVar4 < 1) goto LAB_000bf474;
  }
LAB_000bf592:
  ASN1_STRING_free(a_00);
LAB_000bf18c:
  iVar4 = BIO_write(param_1,"\n",1);
joined_r0x000bf136:
  if (iVar4 < 1) {
LAB_000bf02c:
    pAVar11 = (ASN1_STRING *)0x0;
    a_00 = (ASN1_STRING *)0x0;
    goto LAB_000bf032;
  }
LAB_000bf1a2:
  local_c4 = local_c4 + (int)local_bc;
  if ((local_b8 == 0) && (local_b4 == (ASN1_STRING *)0x0)) {
    pAVar11 = (ASN1_STRING *)0x2;
    a_00 = local_b4;
    goto LAB_000bf032;
  }
LAB_000bf1b6:
  a_00 = (ASN1_STRING *)(uint)(pbVar13 < local_c4);
  if (pbVar8 <= local_c4) {
    a_00 = (ASN1_STRING *)0x0;
  }
  local_e8 = local_e8 - (int)local_bc;
  if (a_00 == (ASN1_STRING *)0x0) goto LAB_000bf36e;
  goto LAB_000befa4;
LAB_000bf36e:
  pAVar11 = (ASN1_STRING *)0x1;
LAB_000bf032:
  if (local_b0 != (ASN1_OBJECT *)0x0) {
    ASN1_OBJECT_free(local_b0);
  }
  if (a_00 != (ASN1_STRING *)0x0) {
    ASN1_STRING_free(a_00);
  }
LAB_000bf040:
  *param_2 = local_c4;
LAB_000bf046:
  if (local_2c == __stack_chk_guard) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(pAVar11);
}

