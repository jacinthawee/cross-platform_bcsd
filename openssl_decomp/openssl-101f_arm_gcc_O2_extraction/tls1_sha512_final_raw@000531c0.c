
void tls1_sha512_final_raw(undefined4 *param_1,undefined *param_2)

{
  undefined *puVar1;
  undefined *puVar2;
  
  puVar1 = param_2;
  do {
    puVar2 = puVar1 + 8;
    *puVar1 = *(undefined *)((int)param_1 + 7);
    puVar1[1] = (char)*(undefined2 *)((int)param_1 + 6);
    puVar1[2] = (char)((uint)param_1[1] >> 8);
    puVar1[3] = (char)param_1[1];
    puVar1[4] = *(undefined *)((int)param_1 + 3);
    puVar1[5] = (char)*(undefined2 *)((int)param_1 + 2);
    puVar1[6] = (char)((uint)*param_1 >> 8);
    puVar1[7] = (char)*param_1;
    param_1 = param_1 + 2;
    puVar1 = puVar2;
  } while (puVar2 != param_2 + 0x40);
  return;
}

