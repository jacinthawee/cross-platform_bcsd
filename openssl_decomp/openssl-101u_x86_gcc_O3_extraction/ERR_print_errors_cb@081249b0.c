
void ERR_print_errors_cb(cb *cb,void *u)

{
  ulong uVar1;
  ulong e;
  char *pcVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint *puVar6;
  uint *puVar7;
  int in_GS_OFFSET;
  bool bVar8;
  char *local_1138;
  char *local_1134;
  int local_1130;
  byte local_112c;
  CRYPTO_THREADID local_1128;
  char local_1120 [256];
  uint local_1020 [1024];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  CRYPTO_THREADID_current(&local_1128);
  uVar1 = CRYPTO_THREADID_hash(&local_1128);
  do {
    e = ERR_get_error_line_data(&local_1138,&local_1130,&local_1134,(int *)&local_112c);
    if (e == 0) break;
    ERR_error_string_n(e,local_1120,0x100);
    pcVar2 = "";
    if ((local_112c & 2) != 0) {
      pcVar2 = local_1134;
    }
    BIO_snprintf((char *)local_1020,0x1000,"%lu:%s:%s:%d:%s\n",uVar1,local_1120,local_1138,
                 local_1130,pcVar2);
    puVar7 = local_1020;
    do {
      puVar6 = puVar7;
      uVar3 = *puVar6 + 0xfefefeff & ~*puVar6;
      uVar4 = uVar3 & 0x80808080;
      puVar7 = puVar6 + 1;
    } while (uVar4 == 0);
    bVar8 = (uVar3 & 0x8080) == 0;
    if (bVar8) {
      uVar4 = uVar4 >> 0x10;
    }
    if (bVar8) {
      puVar7 = (uint *)((int)puVar6 + 6);
    }
    iVar5 = (*cb)((char *)local_1020,
                  (size_t)((int)puVar7 +
                          ((-3 - (uint)CARRY1((byte)uVar4,(byte)uVar4)) - (int)local_1020)),u);
  } while (0 < iVar5);
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

