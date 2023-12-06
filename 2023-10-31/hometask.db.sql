-- ----------------------------
-- Sequence structure for CATALOGS_ID_CATALOG_seq
-- ----------------------------
DROP SEQUENCE IF EXISTS "public"."CATALOGS_ID_CATALOG_seq";
CREATE SEQUENCE "public"."CATALOGS_ID_CATALOG_seq" 
INCREMENT 1
MINVALUE  1
MAXVALUE 2147483647
START 1
CACHE 1;

-- ----------------------------
-- Sequence structure for ORDERS_ID_ORDER_seq
-- ----------------------------
DROP SEQUENCE IF EXISTS "public"."ORDERS_ID_ORDER_seq";
CREATE SEQUENCE "public"."ORDERS_ID_ORDER_seq" 
INCREMENT 1
MINVALUE  1
MAXVALUE 2147483647
START 1
CACHE 1;

-- ----------------------------
-- Sequence structure for PRODUCTS_ID_PRODUCT_seq
-- ----------------------------
DROP SEQUENCE IF EXISTS "public"."PRODUCTS_ID_PRODUCT_seq";
CREATE SEQUENCE "public"."PRODUCTS_ID_PRODUCT_seq" 
INCREMENT 1
MINVALUE  1
MAXVALUE 2147483647
START 1
CACHE 1;

-- ----------------------------
-- Sequence structure for USERS_ID_USER_seq
-- ----------------------------
DROP SEQUENCE IF EXISTS "public"."USERS_ID_USER_seq";
CREATE SEQUENCE "public"."USERS_ID_USER_seq" 
INCREMENT 1
MINVALUE  1
MAXVALUE 2147483647
START 1
CACHE 1;

-- ----------------------------
-- Table structure for CATALOGS
-- ----------------------------
DROP TABLE IF EXISTS "public"."CATALOGS";
CREATE TABLE "public"."CATALOGS" (
  "ID_CATALOG" int4 NOT NULL DEFAULT nextval('"CATALOGS_ID_CATALOG_seq"'::regclass),
  "NAME" text COLLATE "pg_catalog"."default"
)
;

-- ----------------------------
-- Records of CATALOGS
-- ----------------------------
INSERT INTO "public"."CATALOGS" VALUES (1, 'Процессоры');
INSERT INTO "public"."CATALOGS" VALUES (2, 'Материнские платы');
INSERT INTO "public"."CATALOGS" VALUES (3, 'Видеокарты');
INSERT INTO "public"."CATALOGS" VALUES (4, 'HDD');
INSERT INTO "public"."CATALOGS" VALUES (5, 'RAM');

-- ----------------------------
-- Table structure for ORDERS
-- ----------------------------
DROP TABLE IF EXISTS "public"."ORDERS";
CREATE TABLE "public"."ORDERS" (
  "ID_ORDER" int4 NOT NULL DEFAULT nextval('"ORDERS_ID_ORDER_seq"'::regclass),
  "ID_USER" int4,
  "NUMBER" int4,
  "ID_PRODUCT" int4,
  "ORDERTIME" timestamp(6)
)
;

-- ----------------------------
-- Records of ORDERS
-- ----------------------------
INSERT INTO "public"."ORDERS" VALUES (4, 3, 1, 1, '2023-11-01 16:49:22');
INSERT INTO "public"."ORDERS" VALUES (5, 2, 2, 3, '2023-10-04 16:49:56');
INSERT INTO "public"."ORDERS" VALUES (6, 1, 1, 6, '2022-11-01 16:51:04');

-- ----------------------------
-- Table structure for PRODUCTS
-- ----------------------------
DROP TABLE IF EXISTS "public"."PRODUCTS";
CREATE TABLE "public"."PRODUCTS" (
  "ID_PRODUCT" int4 NOT NULL DEFAULT nextval('"PRODUCTS_ID_PRODUCT_seq"'::regclass),
  "NAME" text COLLATE "pg_catalog"."default",
  "PRICE" numeric(10,2),
  "COUNT" int4,
  "MARK" numeric(2,1),
  "DESCRIPTION" text COLLATE "pg_catalog"."default",
  "ID_CATALOG" int4
)
;

-- ----------------------------
-- Records of PRODUCTS
-- ----------------------------
INSERT INTO "public"."PRODUCTS" VALUES (2, 'Celeron 2', 1969.00, 2, 3.7, '---', 1);
INSERT INTO "public"."PRODUCTS" VALUES (1, 'Celeron 1.8', 1595.00, 10, 3.6, '---', 1);
INSERT INTO "public"."PRODUCTS" VALUES (3, 'Celeron 2.4', 2109.00, 4, 3.9, '---', 1);
INSERT INTO "public"."PRODUCTS" VALUES (4, 'Celeron D 320', 1962.00, 6, 4.1, '---', 1);
INSERT INTO "public"."PRODUCTS" VALUES (5, 'Celeron D 325', 2159.00, 24, 4.8, '---', 1);
INSERT INTO "public"."PRODUCTS" VALUES (6, 'Gigabyte GA-231421', 849.00, 12, 3.4, '---', 2);

-- ----------------------------
-- Table structure for USERS
-- ----------------------------
DROP TABLE IF EXISTS "public"."USERS";
CREATE TABLE "public"."USERS" (
  "ID_USER" int4 NOT NULL DEFAULT nextval('"USERS_ID_USER_seq"'::regclass),
  "SURNAME" text COLLATE "pg_catalog"."default",
  "PATRONYMIC" text COLLATE "pg_catalog"."default",
  "NAME" text COLLATE "pg_catalog"."default",
  "PHONE" text COLLATE "pg_catalog"."default",
  "EMAIL" text COLLATE "pg_catalog"."default",
  "URL" text COLLATE "pg_catalog"."default",
  "USERSTATUS" text COLLATE "pg_catalog"."default"
)
;

-- ----------------------------
-- Records of USERS
-- ----------------------------
INSERT INTO "public"."USERS" VALUES (1, 'Иванов', 'Валерьевич', 'Александр', '34342', 'test@test.com', NULL, 'active');
INSERT INTO "public"."USERS" VALUES (2, 'Петров', 'Петр', 'Петрович', '425443', NULL, NULL, 'active');
INSERT INTO "public"."USERS" VALUES (3, 'Семнов', 'Иван', 'Дминтривевич', NULL, NULL, NULL, 'passive');
INSERT INTO "public"."USERS" VALUES (4, 'Тапочка', NULL, NULL, '345', NULL, NULL, 'lock');

-- ----------------------------
-- Alter sequences owned by
-- ----------------------------
ALTER SEQUENCE "public"."CATALOGS_ID_CATALOG_seq"
OWNED BY "public"."CATALOGS"."ID_CATALOG";
SELECT setval('"public"."CATALOGS_ID_CATALOG_seq"', 5, true);

-- ----------------------------
-- Alter sequences owned by
-- ----------------------------
ALTER SEQUENCE "public"."ORDERS_ID_ORDER_seq"
OWNED BY "public"."ORDERS"."ID_ORDER";
SELECT setval('"public"."ORDERS_ID_ORDER_seq"', 1, false);

-- ----------------------------
-- Alter sequences owned by
-- ----------------------------
ALTER SEQUENCE "public"."PRODUCTS_ID_PRODUCT_seq"
OWNED BY "public"."PRODUCTS"."ID_PRODUCT";
SELECT setval('"public"."PRODUCTS_ID_PRODUCT_seq"', 6, true);

-- ----------------------------
-- Alter sequences owned by
-- ----------------------------
ALTER SEQUENCE "public"."USERS_ID_USER_seq"
OWNED BY "public"."USERS"."ID_USER";
SELECT setval('"public"."USERS_ID_USER_seq"', 4, true);

-- ----------------------------
-- Primary Key structure for table CATALOGS
-- ----------------------------
ALTER TABLE "public"."CATALOGS" ADD CONSTRAINT "CATALOGS_pkey" PRIMARY KEY ("ID_CATALOG");

-- ----------------------------
-- Indexes structure for table ORDERS
-- ----------------------------
CREATE INDEX "ORDERS_ID_PRODUCT_idx" ON "public"."ORDERS" USING btree (
  "ID_PRODUCT" "pg_catalog"."int4_ops" ASC NULLS LAST
);
CREATE INDEX "ORDERS_ID_USER_idx" ON "public"."ORDERS" USING btree (
  "ID_USER" "pg_catalog"."int4_ops" ASC NULLS LAST
);

-- ----------------------------
-- Primary Key structure for table ORDERS
-- ----------------------------
ALTER TABLE "public"."ORDERS" ADD CONSTRAINT "ORDERS_pkey" PRIMARY KEY ("ID_ORDER");

-- ----------------------------
-- Indexes structure for table PRODUCTS
-- ----------------------------
CREATE INDEX "PRODUCTS_ID_CATALOG_idx" ON "public"."PRODUCTS" USING btree (
  "ID_CATALOG" "pg_catalog"."int4_ops" ASC NULLS LAST
);

-- ----------------------------
-- Primary Key structure for table PRODUCTS
-- ----------------------------
ALTER TABLE "public"."PRODUCTS" ADD CONSTRAINT "PRODUCTS_pkey" PRIMARY KEY ("ID_PRODUCT");

-- ----------------------------
-- Primary Key structure for table USERS
-- ----------------------------
ALTER TABLE "public"."USERS" ADD CONSTRAINT "USERS_pkey" PRIMARY KEY ("ID_USER");

-- ----------------------------
-- Foreign Keys structure for table ORDERS
-- ----------------------------
ALTER TABLE "public"."ORDERS" ADD CONSTRAINT "ORDERS_ID_PRODUCT_fkey" FOREIGN KEY ("ID_PRODUCT") REFERENCES "public"."PRODUCTS" ("ID_PRODUCT") ON DELETE CASCADE ON UPDATE CASCADE;
ALTER TABLE "public"."ORDERS" ADD CONSTRAINT "ORDERS_ID_USER_fkey" FOREIGN KEY ("ID_USER") REFERENCES "public"."USERS" ("ID_USER") ON DELETE CASCADE ON UPDATE CASCADE;

-- ----------------------------
-- Foreign Keys structure for table PRODUCTS
-- ----------------------------
ALTER TABLE "public"."PRODUCTS" ADD CONSTRAINT "PRODUCTS_ID_CATALOG_fkey" FOREIGN KEY ("ID_CATALOG") REFERENCES "public"."CATALOGS" ("ID_CATALOG") ON DELETE CASCADE ON UPDATE CASCADE;
