
long __regparm3
asn1_i2d_ex_primitive(int *param_1_00,uchar **param_2_00,char *param_3,int param_1,int param_2)

{
  code *pcVar1;
  bool bVar2;
  uchar *puVar3;
  long length;
  int iVar4;
  uchar *__n;
  uchar **ppuVar5;
  int iVar6;
  ASN1_BIT_STRING *pAVar7;
  uchar *__src;
  int *piVar8;
  int in_GS_OFFSET;
  int local_30;
  uchar local_29;
  int local_28;
  uchar *local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  iVar6 = *(int *)(param_3 + 4);
  local_28 = iVar6;
  if ((*(int *)(param_3 + 0x10) == 0) ||
     (pcVar1 = *(code **)(*(int *)(param_3 + 0x10) + 0x18), pcVar1 == (code *)0x0)) {
    piVar8 = param_1_00;
    if ((iVar6 != 1) || (*param_3 != '\0')) {
      pAVar7 = (ASN1_BIT_STRING *)*param_1_00;
      if (pAVar7 != (ASN1_BIT_STRING *)0x0) {
        if (*param_3 == '\x05') {
          local_28 = pAVar7->type;
        }
        else if (iVar6 == -4) {
          piVar8 = &pAVar7->type;
          local_28 = pAVar7->length;
        }
        goto LAB_08148f09;
      }
      goto LAB_08148ed3;
    }
LAB_08148f09:
    if (local_28 == 5) {
      length = 0;
LAB_0814913a:
      bVar2 = true;
      goto LAB_08148e20;
    }
    if (5 < local_28) {
      if (local_28 == 10) {
LAB_0814911c:
        length = i2c_ASN1_INTEGER((ASN1_INTEGER *)*piVar8,(uchar **)0x0);
        goto LAB_08148df8;
      }
      if (local_28 < 0xb) {
        if (local_28 != 6) goto LAB_08148f33;
        length = ((ASN1_BIT_STRING *)*piVar8)->flags;
        goto LAB_08148e0d;
      }
      if ((local_28 == 0x102) || (local_28 == 0x10a)) goto LAB_0814911c;
LAB_08148f33:
      if ((*(int *)(param_3 + 0x14) != 0x800) ||
         ((*(byte *)&((ASN1_BIT_STRING *)*piVar8)->flags & 0x10) == 0)) {
        length = ((ASN1_BIT_STRING *)*piVar8)->length;
        goto LAB_08148df8;
      }
      if ((1 < local_28 - 0x10U) && (local_28 != -3)) {
        length = -2;
        goto LAB_0814913a;
      }
      bVar2 = false;
      goto LAB_08148fe0;
    }
    if (local_28 == 2) goto LAB_0814911c;
    if (local_28 == 3) {
      length = i2c_ASN1_BIT_STRING((ASN1_BIT_STRING *)*piVar8,(uchar **)0x0);
      goto LAB_08148df8;
    }
    if (local_28 != 1) goto LAB_08148f33;
    if ((ASN1_BIT_STRING *)*piVar8 == (ASN1_BIT_STRING *)0xffffffff) goto LAB_08148ed3;
    if (iVar6 != -4) {
      if ((ASN1_BIT_STRING *)*piVar8 == (ASN1_BIT_STRING *)0x0) {
        if (*(int *)(param_3 + 0x14) == 0) {
          length = 0;
          goto LAB_08148ea4;
        }
      }
      else if (0 < *(int *)(param_3 + 0x14)) goto LAB_08148ed3;
      length = 1;
      goto LAB_0814913a;
    }
    length = 1;
    bVar2 = true;
LAB_08148e29:
    local_30 = 0;
  }
  else {
    length = (*pcVar1)(param_1_00,0,&local_28,param_3);
LAB_08148df8:
    if ((local_28 - 0x10U < 2) || (local_28 == -3)) {
      bVar2 = false;
    }
    else {
LAB_08148e0d:
      bVar2 = true;
    }
    if (length == -1) {
LAB_08148ed3:
      length = 0;
      goto LAB_08148ea4;
    }
LAB_08148e20:
    if (length != -2) goto LAB_08148e29;
LAB_08148fe0:
    local_30 = 2;
    length = 0;
  }
  iVar6 = local_28;
  if (param_1 != -1) {
    iVar6 = param_1;
  }
  if (param_2_00 != (uchar **)0x0) {
    if (bVar2) {
      ASN1_put_object(param_2_00,local_30,length,iVar6,param_2);
    }
    local_24 = *param_2_00;
    if ((*(int *)(param_3 + 0x10) == 0) ||
       (pcVar1 = *(code **)(*(int *)(param_3 + 0x10) + 0x18), pcVar1 == (code *)0x0)) {
      if (*param_3 == '\0') {
        iVar4 = *(int *)(param_3 + 4);
        if (iVar4 == 1) goto LAB_08148f6d;
        pAVar7 = (ASN1_BIT_STRING *)*param_1_00;
        if (pAVar7 != (ASN1_BIT_STRING *)0x0) goto LAB_08149003;
      }
      else {
        pAVar7 = (ASN1_BIT_STRING *)*param_1_00;
        if (pAVar7 != (ASN1_BIT_STRING *)0x0) {
          if (*param_3 == '\x05') {
            local_28 = pAVar7->type;
          }
          else {
            iVar4 = *(int *)(param_3 + 4);
LAB_08149003:
            if (iVar4 == -4) {
              local_28 = pAVar7->length;
              param_1_00 = &pAVar7->type;
            }
          }
LAB_08148f6d:
          if (local_28 != 5) {
            if (local_28 < 6) {
              if (local_28 == 2) {
LAB_0814922a:
                ppuVar5 = &local_24;
                if (local_24 == (uchar *)0x0) {
                  ppuVar5 = (uchar **)0x0;
                }
                i2c_ASN1_INTEGER((ASN1_INTEGER *)*param_1_00,ppuVar5);
                goto LAB_08148e78;
              }
              if (local_28 == 3) {
                ppuVar5 = &local_24;
                if (local_24 == (uchar *)0x0) {
                  ppuVar5 = (uchar **)0x0;
                }
                i2c_ASN1_BIT_STRING((ASN1_BIT_STRING *)*param_1_00,ppuVar5);
                goto LAB_08148e78;
              }
              if (local_28 != 1) goto LAB_08148f97;
              iVar4 = *param_1_00;
              if (iVar4 == -1) goto LAB_08148e78;
              if (*(int *)(param_3 + 4) != -4) {
                if (iVar4 == 0) {
                  if (*(int *)(param_3 + 0x14) != 0) goto LAB_081491c5;
                }
                else if (*(int *)(param_3 + 0x14) < 1) goto LAB_081491c5;
                goto LAB_08148e78;
              }
LAB_081491c5:
              local_29 = (uchar)iVar4;
              __src = &local_29;
              __n = (uchar *)0x1;
              puVar3 = local_24;
            }
            else {
              if (local_28 == 10) goto LAB_0814922a;
              if (local_28 < 0xb) {
                if (local_28 != 6) goto LAB_08148f97;
                __src = *(uchar **)(*param_1_00 + 0x10);
                __n = *(uchar **)(*param_1_00 + 0xc);
              }
              else {
                if ((local_28 == 0x102) || (local_28 == 0x10a)) goto LAB_0814922a;
LAB_08148f97:
                ppuVar5 = (uchar **)*param_1_00;
                if ((*(int *)(param_3 + 0x14) == 0x800) && ((*(byte *)(ppuVar5 + 3) & 0x10) != 0)) {
                  if (local_24 != (uchar *)0x0) {
                    ppuVar5[2] = local_24;
                    *ppuVar5 = (uchar *)0x0;
                  }
                  goto LAB_08148e78;
                }
                __src = ppuVar5[2];
                __n = *ppuVar5;
              }
              puVar3 = __n;
              if (local_24 == (uchar *)0x0) goto LAB_08148e78;
            }
            if (puVar3 != (uchar *)0x0) {
              memcpy(local_24,__src,(size_t)__n);
            }
          }
        }
      }
    }
    else {
      (*pcVar1)(param_1_00,local_24,&local_28,param_3);
    }
LAB_08148e78:
    if (local_30 == 0) {
      *param_2_00 = *param_2_00 + length;
    }
    else {
      ASN1_put_eoc(param_2_00);
    }
  }
  if (bVar2) {
    length = ASN1_object_size(local_30,length,iVar6);
  }
LAB_08148ea4:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return length;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

