BEGIN TRANSACTION;
INSERT INTO customers ("customerId", "customerName", "phone")
VALUES (1, 'Заказчик 1', '000'),(2, 'Заказчик 2', '000');

INSERT INTO products("productId", "productName", "price")
VALUES (1, 'Бананы',130.3);

INSERT INTO suppliers("supplierId", "supplierName", address, phone)
VALUES (1, 'Обезьяны', 'Африка', '111');

INSERT INTO orders("orderId", "customerId", "productId", quantity, "createdAt")
VALUES(1,1,1,3, now());

INSERT INTO payments("paymentId", "orderId", amount, "createdAt")
VALUES(1,1,100,now());

INSERT INTO orders("orderId", "customerId", "productId", quantity, "createdAt")
VALUES(2,2,1,3, now());


INSERT INTO payments("paymentId", "orderId", amount, "createdAt")
VALUES(2,2,55,now());


ROLLBACK;