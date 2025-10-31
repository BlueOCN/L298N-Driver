#include <Arduino.h>
#include <unity.h>
#include "PinView.h"

void test_pinview_indexing() {
    uint8_t pins[] = {2, 4, 7, 8};
    PinView view{pins, 4};

    TEST_ASSERT_EQUAL_UINT8(2, view[0]);
    TEST_ASSERT_EQUAL_UINT8(4, view[1]);
    TEST_ASSERT_EQUAL_UINT8(7, view[2]);
    TEST_ASSERT_EQUAL_UINT8(8, view[3]);
}

void test_pinview_size() {
    uint8_t pins[] = {3, 5};
    PinView view{pins, 2};

    TEST_ASSERT_EQUAL_UINT8(2, view.getSize());
}

void test_pinview_iteration() {
    uint8_t pins[] = {9, 10, 11};
    PinView view{pins, 3};

    uint8_t expected[] = {9, 10, 11};
    uint8_t i = 0;
    for (auto pin : view) {
        TEST_ASSERT_EQUAL_UINT8(expected[i], pin);
        i++;
    }
    TEST_ASSERT_EQUAL_UINT8(3, i); // Ensure loop ran correct number of times
}

void setup() {
    delay(1000); // Wait for serial monitor
    UNITY_BEGIN();

    RUN_TEST(test_pinview_indexing);
    RUN_TEST(test_pinview_size);
    RUN_TEST(test_pinview_iteration);

    UNITY_END();
}

void loop() {
    // Nothing here
}
