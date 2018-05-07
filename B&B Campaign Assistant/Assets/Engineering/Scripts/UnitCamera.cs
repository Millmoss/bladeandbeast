using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class UnitCamera : MonoBehaviour
{
	public Camera playerCamera;
	public Transform cameraFocus;
	public float xSensitivity = 1f;
	public float ySensitivity = -1;
	public float moveSentivity = 1;
	private Vector3 playerChange;
	private float xLook;
	private float yLook;
	private float xMove;
	private float zMove;
	private float rotateSpeed;
	private float moveSpeed;
	public bool mouseLock = true;
	private bool rotateCamera = false;
	private float yRotationDif = 0;
	private float scrollPosition;

	void Start()
	{
		scrollPosition = 3;
		transform.position = cameraFocus.position - (cameraFocus.position - new Vector3(cameraFocus.transform.position.x, cameraFocus.transform.position.y + 1f, cameraFocus.transform.position.z - 1f)).normalized * 10 / scrollPosition;
		cameraFocus.LookAt(Camera.main.transform);
		playerCamera.transform.Rotate(Vector3.right, 45);
		playerChange = cameraFocus.transform.position;
		rotateSpeed = 20f;
		//transform.RotateAround(cameraFocus.transform.position, Vector3.up, 180);
		yRotationDif = transform.rotation.eulerAngles.y - yRotationDif;
		cameraFocus.transform.Rotate(Vector3.up, yRotationDif);
		yRotationDif = transform.rotation.eulerAngles.y;
	}

	void Update()
	{
		if (Input.GetKeyUp(KeyCode.Escape) || Input.GetKeyUp(KeyCode.LeftAlt))
		{
			mouseLock = !mouseLock;
		}

		//camera move input
		
		if (Input.GetMouseButton(1))
		{
			if (Input.GetMouseButtonDown(1))
			{
				Cursor.visible = false;
				rotateCamera = true;
				Cursor.lockState = CursorLockMode.Confined;
			}
			xLook += xSensitivity * Input.GetAxis("Mouse X") * .25f;
			yLook += ySensitivity * Input.GetAxis("Mouse Y") * .25f;
			if (xLook > 180f)
				xLook -= 360f;
			if (xLook < -180f)
				xLook += 360f;
			if (yLook >= 90f)
				yLook = 89f;
			if (yLook < -45f)
				yLook = -45f;
		}
		else if (Input.GetMouseButtonUp(1))
		{
			Cursor.visible = true;
			rotateCamera = false;
			Cursor.lockState = CursorLockMode.None;
		}

		if (Input.GetKey(KeyCode.LeftShift))
			moveSpeed = 2;
		else
			moveSpeed = 5;

		xMove = 0;
		zMove = 0;

		if (Input.GetKey(KeyCode.W) || Input.GetKey(KeyCode.UpArrow))
		{
			zMove -= 1;
		}
		if (Input.GetKey(KeyCode.A) || Input.GetKey(KeyCode.LeftArrow))
		{
			xMove += 1;
		}
		if (Input.GetKey(KeyCode.S) || Input.GetKey(KeyCode.DownArrow))
		{
			zMove += 1;
		}
		if (Input.GetKey(KeyCode.D) || Input.GetKey(KeyCode.RightArrow))
		{
			xMove -= 1;
		}

		Vector3 clampedMove = Vector3.ClampMagnitude(new Vector3(xMove, 0, zMove), 1);
		xMove = clampedMove.x;
		zMove = clampedMove.z;

		scrollPosition += Input.GetAxis("Mouse ScrollWheel");
		if (scrollPosition < 1)
			scrollPosition = 1;
		else if (scrollPosition > 25)
			scrollPosition = 25;

		if (xMove > 0)
			cameraFocus.transform.position -= cameraFocus.transform.right / moveSpeed * Time.deltaTime * 30;
		else if (xMove < 0)
			cameraFocus.transform.position += cameraFocus.transform.right / moveSpeed * Time.deltaTime * 30;
		if (zMove > 0)
			cameraFocus.transform.position -= cameraFocus.transform.forward / moveSpeed * Time.deltaTime * 30;
		else if (zMove < 0)
			cameraFocus.transform.position += cameraFocus.transform.forward / moveSpeed * Time.deltaTime * 30;

		transform.eulerAngles = new Vector3(0, xLook, 0);
		playerCamera.transform.localEulerAngles = new Vector3(yLook, 0);
		transform.position = cameraFocus.position - playerCamera.transform.forward * 25 / scrollPosition;
		cameraFocus.transform.eulerAngles = new Vector3(0.0f, xLook, 0.0f);
	}
}
