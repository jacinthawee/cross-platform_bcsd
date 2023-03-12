
_STACK * i2v_AUTHORITY_INFO_ACCESS(X509V3_EXT_METHOD *param_1,_STACK *param_2,_STACK *param_3)

{
  ASN1_OBJECT **ppAVar1;
  void *pvVar2;
  uint uVar3;
  uint uVar4;
  size_t sVar5;
  char *dst;
  int iVar6;
  int iVar7;
  uint *puVar8;
  uint *puVar9;
  int in_GS_OFFSET;
  bool bVar10;
  _STACK *local_80;
  uint local_70 [20];
  int local_20;
  
  iVar7 = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_80 = param_3;
  do {
    iVar6 = sk_num(param_2);
    if (iVar6 <= iVar7) {
      if (local_80 == (_STACK *)0x0) {
LAB_08174f20:
        local_80 = sk_new_null();
      }
LAB_08174f08:
      if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
        return local_80;
      }
                    /* WARNING: Subroutine does not return */
      __stack_chk_fail();
    }
    ppAVar1 = (ASN1_OBJECT **)sk_value(param_2,iVar7);
    local_80 = (_STACK *)
               i2v_GENERAL_NAME(param_1,(GENERAL_NAME *)ppAVar1[1],(stack_st_CONF_VALUE *)local_80);
    if (local_80 == (_STACK *)0x0) goto LAB_08174f20;
    pvVar2 = sk_value(local_80,iVar7);
    i2t_ASN1_OBJECT((char *)local_70,0x50,*ppAVar1);
    puVar9 = local_70;
    do {
      puVar8 = puVar9;
      uVar3 = *puVar8 + 0xfefefeff & ~*puVar8;
      uVar4 = uVar3 & 0x80808080;
      puVar9 = puVar8 + 1;
    } while (uVar4 == 0);
    bVar10 = (uVar3 & 0x8080) == 0;
    if (bVar10) {
      uVar4 = uVar4 >> 0x10;
    }
    if (bVar10) {
      puVar9 = (uint *)((int)puVar8 + 6);
    }
    sVar5 = strlen(*(char **)((int)pvVar2 + 4));
    sVar5 = (int)puVar9 + sVar5 + (-(int)local_70 - (uint)CARRY1((byte)uVar4,(byte)uVar4)) + 2;
    dst = (char *)CRYPTO_malloc(sVar5,"v3_info.c",0x76);
    if (dst == (char *)0x0) {
      ERR_put_error(0x22,0x8a,0x41,"v3_info.c",0x79);
      local_80 = (_STACK *)0x0;
      goto LAB_08174f08;
    }
    iVar7 = iVar7 + 1;
    BUF_strlcpy(dst,(char *)local_70,sVar5);
    BUF_strlcat(dst," - ",sVar5);
    BUF_strlcat(dst,*(char **)((int)pvVar2 + 4),sVar5);
    CRYPTO_free(*(void **)((int)pvVar2 + 4));
    *(char **)((int)pvVar2 + 4) = dst;
  } while( true );
}

