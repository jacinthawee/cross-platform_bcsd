
long __regparm3
asn1_i2d_ex_primitive(int *param_1_00,uchar **param_2_00,char *param_3,int param_1,int param_2)

{
  code *pcVar1;
  size_t *psVar2;
  bool bVar3;
  long length;
  int iVar4;
  uchar **ppuVar5;
  size_t __n;
  int iVar6;
  ASN1_BIT_STRING *pAVar7;
  undefined *__src;
  int *piVar8;
  int in_GS_OFFSET;
  int local_30;
  undefined local_29;
  int local_28;
  uchar *local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  iVar6 = *(int *)(param_3 + 4);
  local_28 = iVar6;
  if ((*(int *)(param_3 + 0x10) != 0) &&
     (pcVar1 = *(code **)(*(int *)(param_3 + 0x10) + 0x18), pcVar1 != (code *)0x0)) {
    length = (*pcVar1)(param_1_00,0,&local_28,param_3);
    goto LAB_08146258;
  }
  piVar8 = param_1_00;
  if ((iVar6 == 1) && (*param_3 == '\0')) {
LAB_08146369:
    switch(local_28) {
    default:
      if ((*(int *)(param_3 + 0x14) != 0x800) ||
         ((*(byte *)&((ASN1_BIT_STRING *)*piVar8)->flags & 0x10) == 0)) {
        length = ((ASN1_BIT_STRING *)*piVar8)->length;
        break;
      }
      if ((1 < local_28 - 0x10U) && (local_28 != -3)) {
        length = -2;
        goto LAB_08146442;
      }
      bVar3 = false;
      goto LAB_081463e8;
    case 1:
      if ((ASN1_BIT_STRING *)*piVar8 == (ASN1_BIT_STRING *)0xffffffff) goto LAB_08146333;
      if (iVar6 != -4) {
        if ((ASN1_BIT_STRING *)*piVar8 == (ASN1_BIT_STRING *)0x0) {
          if (*(int *)(param_3 + 0x14) == 0) {
            length = 0;
            goto LAB_08146304;
          }
        }
        else if (0 < *(int *)(param_3 + 0x14)) goto LAB_08146333;
        length = 1;
        goto LAB_08146442;
      }
      length = 1;
      bVar3 = true;
      goto LAB_08146289;
    case 2:
    case 10:
      length = i2c_ASN1_INTEGER((ASN1_INTEGER *)*piVar8,(uchar **)0x0);
      break;
    case 3:
      length = i2c_ASN1_BIT_STRING((ASN1_BIT_STRING *)*piVar8,(uchar **)0x0);
      break;
    case 5:
      length = 0;
LAB_08146442:
      bVar3 = true;
      goto LAB_08146280;
    case 6:
      length = ((ASN1_BIT_STRING *)*piVar8)->flags;
      goto LAB_0814626d;
    }
LAB_08146258:
    if ((local_28 - 0x10U < 2) || (local_28 == -3)) {
      bVar3 = false;
    }
    else {
LAB_0814626d:
      bVar3 = true;
    }
    if (length != -1) {
LAB_08146280:
      if (length == -2) {
LAB_081463e8:
        local_30 = 2;
        length = 0;
      }
      else {
LAB_08146289:
        local_30 = 0;
      }
      iVar6 = local_28;
      if (param_1 != -1) {
        iVar6 = param_1;
      }
      if (param_2_00 != (uchar **)0x0) {
        if (bVar3) {
          ASN1_put_object(param_2_00,local_30,length,iVar6,param_2);
        }
        local_24 = *param_2_00;
        if ((*(int *)(param_3 + 0x10) == 0) ||
           (pcVar1 = *(code **)(*(int *)(param_3 + 0x10) + 0x18), pcVar1 == (code *)0x0)) {
          if (*param_3 == '\0') {
            iVar4 = *(int *)(param_3 + 4);
            if (iVar4 == 1) goto LAB_0814639d;
            pAVar7 = (ASN1_BIT_STRING *)*param_1_00;
            if (pAVar7 != (ASN1_BIT_STRING *)0x0) goto LAB_08146413;
          }
          else {
            pAVar7 = (ASN1_BIT_STRING *)*param_1_00;
            if (pAVar7 != (ASN1_BIT_STRING *)0x0) {
              if (*param_3 == '\x05') {
                local_28 = pAVar7->type;
              }
              else {
                iVar4 = *(int *)(param_3 + 4);
LAB_08146413:
                if (iVar4 == -4) {
                  local_28 = pAVar7->length;
                  param_1_00 = &pAVar7->type;
                }
              }
LAB_0814639d:
              switch(local_28) {
              default:
                psVar2 = (size_t *)*param_1_00;
                if ((*(int *)(param_3 + 0x14) != 0x800) || ((*(byte *)(psVar2 + 3) & 0x10) == 0)) {
                  __src = (undefined *)psVar2[2];
                  __n = *psVar2;
                  goto LAB_08146559;
                }
                if (local_24 != (uchar *)0x0) {
                  psVar2[2] = (size_t)local_24;
                  *psVar2 = 0;
                }
                break;
              case 1:
                iVar4 = *param_1_00;
                if (iVar4 != -1) {
                  if (*(int *)(param_3 + 4) != -4) {
                    if (iVar4 == 0) {
                      if (*(int *)(param_3 + 0x14) != 0) goto LAB_081465f1;
                    }
                    else if (*(int *)(param_3 + 0x14) < 1) goto LAB_081465f1;
                    break;
                  }
LAB_081465f1:
                  local_29 = (undefined)iVar4;
                  __src = &local_29;
                  __n = 1;
                  if (local_24 == (uchar *)0x0) break;
                  goto LAB_08146569;
                }
                break;
              case 2:
              case 10:
                ppuVar5 = &local_24;
                if (local_24 == (uchar *)0x0) {
                  ppuVar5 = (uchar **)0x0;
                }
                i2c_ASN1_INTEGER((ASN1_INTEGER *)*param_1_00,ppuVar5);
                break;
              case 3:
                ppuVar5 = &local_24;
                if (local_24 == (uchar *)0x0) {
                  ppuVar5 = (uchar **)0x0;
                }
                i2c_ASN1_BIT_STRING((ASN1_BIT_STRING *)*param_1_00,ppuVar5);
                break;
              case 5:
                break;
              case 6:
                __src = *(undefined **)(*param_1_00 + 0x10);
                __n = *(size_t *)(*param_1_00 + 0xc);
LAB_08146559:
                if ((local_24 != (uchar *)0x0) && (__n != 0)) {
LAB_08146569:
                  memcpy(local_24,__src,__n);
                }
              }
            }
          }
        }
        else {
          (*pcVar1)(param_1_00,local_24,&local_28,param_3);
        }
        if (local_30 == 0) {
          *param_2_00 = *param_2_00 + length;
        }
        else {
          ASN1_put_eoc(param_2_00);
        }
      }
      if (bVar3) {
        length = ASN1_object_size(local_30,length,iVar6);
      }
      goto LAB_08146304;
    }
  }
  else {
    pAVar7 = (ASN1_BIT_STRING *)*param_1_00;
    if (pAVar7 != (ASN1_BIT_STRING *)0x0) {
      if (*param_3 == '\x05') {
        local_28 = pAVar7->type;
      }
      else if (iVar6 == -4) {
        piVar8 = &pAVar7->type;
        local_28 = pAVar7->length;
      }
      goto LAB_08146369;
    }
  }
LAB_08146333:
  length = 0;
LAB_08146304:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return length;
}

