
void OPENSSL_rdtsc(void)

{
  if ((OPENSSL_armcap_P & 2) == 0) {
    return;
  }
  ___armv7_tick_from_thumb();
  return;
}

